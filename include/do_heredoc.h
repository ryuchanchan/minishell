#ifndef DO_HEREDOC_H
# define DO_HEREDOC_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "command.h"
# include "ms_error.h"

# define PREFIX_HEREDOC "heredoc> "

int	do_heredoc(char *str, int tmpin, int tmpout);

#endif
