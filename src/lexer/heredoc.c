#include"lexer.h"
#include <readline/readline.h>
#include <readline/history.h>

int	do_heredoc(char *str)
{
	int	fd_pipe[2];
	char *line;

	if (pipe(fd_pipe) < 0)
		return(-1);
	line = readline("> ");
	while (line && ft_strncmp(line, str, ft_strlen(str) + 1) != 0)
	{
		write(fd_pipe[1], line, ft_strlen(line));
		write(fd_pipe[1], "\n", 1);
		free(line);
		line = readline("> ");
	}
	if (line)
		free(line);
	close(fd_pipe[1]);
	return (fd_pipe[0]);
}