#ifndef FD_UTIL_H
# define FD_UTIL_H

# include <unistd.h>

# include "ms_error.h"

void	safe_dup2(int fildes, int fildes2, char *msg_err);

#endif
