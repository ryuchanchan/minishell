#ifndef DO_REDIRECT_H
# define DO_REDIRECT_H

# include <fcntl.h>

# include "command.h"
# include "ms_error.h"
# include "do_heredoc.h"

bool	do_redirect(t_list *command, int fdin, int tmpin, int tmpout);

#endif
