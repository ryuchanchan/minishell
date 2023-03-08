#ifndef EXPANTION_H
# define EXPANTION_H

# include "quotes.h"

typedef struct	e_expansions
{
	size_t			i;
	size_t			j;
	const char		*src;
	char			*dest;
	t_status_quotes status;
}	t_expansions;

void	replace_var(t_expansions *ex);
char	*expansion(const char *src);

#endif