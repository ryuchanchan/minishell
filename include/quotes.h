#ifndef QUOTES_H
# define QUOTES_H

# include <stdbool.h>
# include "../libft/include/libft.h"

typedef enum e_status_quotes
{
	NONE,
	IN_SINGLE_QUOTE,
	IN_DOUBLE_QUOTE
}	t_status_quotes;

bool	is_quote_end(const t_status_quotes status, const char *src, size_t i);
bool	is_double_quote_begin(const t_status_quotes status, const char *src, size_t i);
bool	is_single_quote_begin(const t_status_quotes status, const char *src, size_t i);
void	update_status(t_status_quotes *status, t_status_quotes next, size_t *i_p);

#endif
