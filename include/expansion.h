#ifndef EXPANTION_H
# define EXPANTION_H

# include "quotes.h"
# include "token.h"

typedef struct	e_expansions
{
	size_t			i;
	size_t			j;
	const char		*src;
	char			*dest;
	t_status_quotes status;
}	t_expansions;

char	*expansion(const char *src);
void	replace_var(t_expansions *ex);

#endif
