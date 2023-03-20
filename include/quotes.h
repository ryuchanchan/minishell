#ifndef QUOTES_H
# define QUOTES_H

# include <stdbool.h>
# include "../libft/include/libft.h"

typedef enum e_q_status
{
	Q_NONE,
	Q_IN_SINGLE_QUOTE,
	Q_IN_DOUBLE_QUOTE
}	t_q_status;

bool	is_quote_end(t_q_status status, char *src, size_t i);
bool	is_double_quote_begin(t_q_status status, char *src, size_t i);
bool	is_single_quote_begin(t_q_status status, char *src, size_t i);
void	update_status(t_q_status *status, t_q_status new, size_t *i_p);

#endif
