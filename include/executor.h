#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "command.h"
# include "ms_error.h"

# define PREFIX_HEREDOC "heredoc> "

bool	do_redirect(t_list *command, int fdin, int tmpin, int tmpout);
int		do_heredoc(char *str, int tmpin, int tmpout);
void    executor(t_list *commands, char ***envp_p);

#endif
