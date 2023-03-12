#include "executor.h"

void	executor(t_list *commands, char ***envp_p)
{
	t_list	*command;
	int		fdin;
	int		fdout;
	int		pipe_fd[2];
	int tmpin;
	int tmpout;
	char **arr;

	tmpin = dup(0);
	tmpout = dup(1);
	fdin = dup(tmpin);
	command = commands;
	while (command)
	{
		redirect_input(((t_command *)command->content)->redirections, &fdin, tmpin, tmpout);
		dup2(fdin, 0);
		close(fdin);
		if (command->next)
		{
			pipe(pipe_fd);
			fdout = pipe_fd[1];
			fdin = pipe_fd[0];
		}
		else
			fdout = dup(tmpout);
		redirect_output(((t_command *)command->content)->redirections, &fdout);
		dup2(fdout, 1);
		close(fdout);
		arr = list_to_array(((t_command *)command->content)->args);
		((t_command *)command->content)->pid = fork();
		if (((t_command *)command->content)->pid == 0)
		{
			execve(arr[0], arr, *envp_p);
			perror(arr[0]);
			exit(1);
		}
		free(arr);
		command = command->next;
	}
	dup2(tmpin,0);
	dup2(tmpout,1);
	close(tmpin);
	close(tmpout);
	command = commands;
	while (command)
	{
		ft_printf("wait!!! :%d\n", ((t_command *)command->content)->pid);
		waitpid(((t_command *)command->content)->pid, &((t_command *)command->content)->status, 0);
		command = command->next;
	}
}
