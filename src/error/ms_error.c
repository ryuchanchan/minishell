#include "ms_error.h"

void	fatal_error(char *str)
{
	perror(str);
	exit(STATUS_ERR);
}