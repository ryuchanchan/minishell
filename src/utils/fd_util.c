#include "fd_util.h"

void	safe_dup2(int fildes, int fildes2, char *msg_err)
{
	if (dup2(fildes, fildes2) < 0)
		fatal_error(msg_err);
}
