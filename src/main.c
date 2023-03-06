#include "minishell.h"

/* begin: for debug  */
__attribute__((destructor))
void	destructor(void)
{
	int	status;

	status = system("leaks minishell &> result_leaks");
	if (status)
	{
		write(2, "Memory leak is found!\n", 8);
		system("cat result_leaks >/dev/stderr");
		exit(1);
	}
}
/* end: for debug */

static void	minishell(char *line)
{
	t_list	*list;
	t_list	*head;
	t_node	*node;
	t_list	*command;
	t_pid	pid;
    int		fdin;
    int		fdout;
	int		pipe_fd[2];
	int tmpin = dup(0);
    int tmpout = dup(1);
	char **arr;
	extern char	**environ;
	int status;

	// ft_printf("%s\n", line);
	list = tokenizer(line);
	head = list;
	// while (list != NULL)
	// {
	// 	// printf("%s\n", (char*)list->content);
	// 	list = list->next;
	// }
	node = parser(head);
	fdin = dup(tmpin);
	while (node != NULL)
	{
		command = node->commands;
		redirect_input(node->filenames, &fdin);
		dup2(fdin, 0);
		close(fdin);
		if (node->next != NULL)
		{
			pipe(pipe_fd);
			fdout = pipe_fd[1];
			fdin = pipe_fd[0];
		}
		else
			fdout = dup(tmpout);
		redirect_output(node->filenames, &fdout);
		// print_filenames(node->filenames, &fdout);
		dup2(fdout, 1);
		close(fdout);
		arr = list_to_array(command);
		pid.pids = fork();
		if (pid.pids == 0)
		{
			execve(arr[0], arr, environ);
			perror(arr[0]);
			exit(1);
		}
		free(arr);
		node = node->next;
	}
	dup2(tmpin,0);
	dup2(tmpout,1);
	close(tmpin);
	close(tmpout);
	waitpid(pid.pids, &status, 0);
}

static void update_line(char **line_p)
{
	free(*line_p);
	*line_p = readline(PREFIX_SHELL);
}

int	main(int argc, char **argv, char **envp)
{
	char *line;

	(void)argc;
	(void)argv;
	(void)envp;
	set_signal();
	line = readline(PREFIX_SHELL);
	while (line)
	{
		if (ft_strlen(line) <= 0)
		{
			update_line(&line);
			continue;
		}
		minishell(line);
		add_history(line);
		update_line(&line);
	}
	ft_printf("exit\n");
	rl_clear_history();
	return (0);
}
