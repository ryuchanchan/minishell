#include "executor.h"

static void initialize_fds(int *tmpin_p, int *tmpout_p)
{
	*tmpin_p = dup(STDIN_FILENO);
	if (*tmpin_p < 0)
		fatal_error("executor");
	*tmpout_p = dup(STDOUT_FILENO);
	if (*tmpout_p < 0)
		fatal_error("executor");
}

static void finalize_fds(int tmpin, int tmpout)
{
	if (dup2(tmpin, STDIN_FILENO) < 0)
		fatal_error("executor");
	if (dup2(tmpout, STDOUT_FILENO) < 0)
		fatal_error("executor");
	close(tmpin);
	close(tmpout);
}

static int get_exit_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	return (-1);
}

static int	wait_childs(t_list *commands, bool is_piped)
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
			if (waitpid(c_p->pid, &(c_p->status), 0) < 0)
				fatal_error("executor");
		if (!command->next)
		{
			if (c_p->pid == 0 && !is_piped)
				status = c_p->status;
			else
				status = get_exit_status(c_p->status);
		}
		command = command->next;
	}
	return (status);
}

void	executor(t_list *commands, t_ms_state *state_p)
{
	t_list	*command;
	int		fdin;
	int		tmpin;
	int		tmpout;
	bool	is_piped;

	initialize_fds(&tmpin, &tmpout);
	fdin = dup(tmpin);
	command = commands;
	is_piped = (command->next != NULL);
	while (command)
	{
		if (do_redirect(command, fdin, tmpin, tmpout))
		{
			command = command->next;
			continue ;
		}
		do_exec(command->content, &(state_p->envp), is_piped);
		command = command->next;
	}
	finalize_fds(tmpin, tmpout);
	state_p->exit_status = wait_childs(commands, is_piped);
}
