#include"executor.h"

int	do_heredoc(char *str, int tmpin, int tmpout)
{
	int		fd_pipe[2];
	char	*line;

	dup2(tmpin, STDIN_FILENO);
	dup2(tmpout, STDOUT_FILENO);
	if (pipe(fd_pipe) < 0)
		fatal_error("executor");
	line = readline(PREFIX_HEREDOC);
	while (line && ft_strncmp(line, str, ft_strlen(str) + 1) != 0)
	{
		ft_putendl_fd(line, fd_pipe[1]);
		free(line);
		line = readline(PREFIX_HEREDOC);
	}
	if (line)
		free(line);
	close(fd_pipe[1]);
	return (fd_pipe[0]);
}
