#include "do_heredoc.h"

void initialize_heredoc(int tmpin, int tmpout)
{
	if (dup2(tmpin, STDIN_FILENO) < 0)
		fatal_error("executor");
	if (dup2(tmpout, STDOUT_FILENO) < 0)
		fatal_error("executor");
}

int	do_heredoc(char *str, int tmpin, int tmpout)
{
	int		fd_pipe[2];
	char	*line;

	initialize_heredoc(tmpin, tmpout);
	if (pipe(fd_pipe) < 0)
		fatal_error("executor");
	line = "";
	while (line)
	{
		line = readline(PREFIX_HEREDOC);
		if (!line || ft_strncmp(line, str, ft_strlen(str) + 1) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd_pipe[1]);
		free(line);
	}
	close(fd_pipe[1]);
	return (fd_pipe[0]);
}