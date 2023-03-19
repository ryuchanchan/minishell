#ifndef EXPANTION_H
# define EXPANTION_H

# include "quotes.h"
# include "token.h"
# include "ms_state.h"
# include "ms_error.h"
# include "ms_env.h"

typedef struct	e_expansions
{
	size_t			i;
	size_t			j;
	const char		*src;
	char			*dest;
	t_status_quotes status;
}	t_expansions;

char	*expansion(const char *src, t_ms_state *state_p);
void	replace_var(t_expansions *ex, t_ms_state *state_p);

#endif
