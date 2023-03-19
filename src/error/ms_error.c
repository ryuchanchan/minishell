#include "ms_error.h"

void	fatal_error(char *str)
{
	perror(str);
	exit(STAT_FATAL_ERR);
}

void	print_quote_error(void)
{
	ft_putendl_fd(MSG_SYNTAX_ERR_QUOTE, STDERR_FILENO);
}

void	print_syntax_error(char *str)
{
	ft_putstr_fd(MSG_SYNTAX_ERR_PREFIX, STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putendl_fd(MSG_SYNTAX_ERR_SUFFIX, STDERR_FILENO);
}
