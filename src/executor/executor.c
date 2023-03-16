#include "executor.h"

static char    **list_to_array(t_list *list)
{
    size_t  i;
    size_t  len;
    char    **arr;

    len = (size_t)ft_lstsize(list);
    arr = (char **)malloc(sizeof(char *) * (len + 1));
    if (!arr)
		fatal_error("executor");
	i = 0;
    while (list != NULL)
    {
        arr[i++] = (char *)list->content;
        list = list->next;
    }
    arr[i] = NULL;
    return (arr);
}

static void initialize_fds(int *tmpin_p, int *tmpout_p)
{
	*tmpin_p = dup(STDIN_FILENO);
	*tmpout_p = dup(STDOUT_FILENO);
}

static void finalize_fds(int tmpin, int tmpout)
{
	dup2(tmpin, STDIN_FILENO);
	dup2(tmpout, STDOUT_FILENO);
	close(tmpin);
	close(tmpout);
}

static void	do_exec(t_list *command, char ***envp_p)
{
	char **args;

	if (!((t_command *)command->content)->args)
		return ;
	args = list_to_array(((t_command *)command->content)->args);
	if (!args)
		fatal_error("executor");
	((t_command *)command->content)->pid = fork();
	if (((t_command *)command->content)->pid == 0)
	{
		execve(args[0], args, *envp_p);
		fatal_error(args[0]);
	}
	if (((t_command *)command->content)->pid < 0)
		fatal_error("executor");
	free(args);
}

static int	wait_childs(t_list *commands)
{
	t_list		*command;
	t_command	*c_p;
	int			status;

	status = 0;
	command = commands;
	while (command)
	{
		c_p = command->content;
		if (c_p->pid > 0)
		{
			waitpid(c_p->pid, &(c_p->status), 0);
			if (!command->next)
			{
				(void)status;
			}
		}
		command = command->next;
	}
	return (status);
}

void	executor(t_list *commands, char ***envp_p)
{
	t_list	*command;
	int		fdin;
	int		tmpin;
	int		tmpout;

	initialize_fds(&tmpin, &tmpout);
	fdin = dup(tmpin);
	command = commands;
	while (command)
	{
		if (do_redirect(command, fdin, tmpin, tmpout))
		{
			command = command->next;
			continue ;
		}
		do_exec(command, envp_p);
		command = command->next;
	}
	finalize_fds(tmpin, tmpout);
	(void)wait_childs(commands);
}
