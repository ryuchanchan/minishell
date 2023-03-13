#include"executor.h"
#include <readline/readline.h>
#include <readline/history.h>

int	do_heredoc(char *str, int tmpin, int tmpout)
{
	int		fd_pipe[2];
	char	*line;

	dup2(tmpin, STDIN_FILENO);
	dup2(tmpout, STDOUT_FILENO);
	if (pipe(fd_pipe) < 0)
		return (-1);
	line = readline("heredoc> ");
	while (line && ft_strncmp(line, str, ft_strlen(str) + 1) != 0)
	{
		ft_putendl_fd(line, fd_pipe[1]);
		free(line);
		line = readline("heredoc> ");
	}
	if (line)
		free(line);
	close(fd_pipe[1]);
	return (fd_pipe[0]);
}
