#include "minishell.h"

/* begin: for debug  */
__attribute__((destructor))
void	destructor(void)
{
	int	status;

	status = system("leaks minishell &> result_leaks");
	if (status)
	{
		write(2, "memory leak is found\n", 8);
		system("cat result_leaks >/dev/stderr");
		exit(1);
	}
}
/* end: for debug */

static void	minishell(char *line)
{
	printf("%s\n", line);
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
		if (strlen(line) <= 0)//libc
		{
			update_line(&line);
			continue;
		}
		minishell(line);
		add_history(line);
		update_line(&line);
	}
	printf("exit\n");
	rl_clear_history();
	return (0);
}
