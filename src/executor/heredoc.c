#include"executor.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static volatile sig_atomic_t is_interrupted = 0;

static void signal_handler(int signum)
{
    if (signum == SIGINT)
    {
        is_interrupted = 1;
		rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
}


int	do_heredoc(char *str, int tmpin, int tmpout)
{
	int	fd_pipe[2];
	char *line;

	dup2(tmpin, 0);
	dup2(tmpout, 1);
	if (pipe(fd_pipe) < 0)
		return(-1);
	line = readline("heredoc> ");
	// set_signal();
	signal(SIGINT, signal_handler);
	while (line && ft_strncmp(line, str, ft_strlen(str) + 1) != 0)
	{
		write(fd_pipe[1], line, ft_strlen(line));
		write(fd_pipe[1], "\n", 1);
		free(line);
		line = readline("heredoc> ");
		if (is_interrupted == 1)
		{
			// free(line);
			// close(fd_pipe[0]);
            // close(fd_pipe[1]);
			return (-1);
        }
	}
	if (line)
		free(line);
	close(fd_pipe[1]);
	return (fd_pipe[0]);
}
