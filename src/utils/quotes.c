#include "quotes.h"

bool	is_quote_end(t_q_status status, char *src, size_t i)
{
	if (status == Q_IN_SINGLE_QUOTE && src[i] == '\'')
		return (true);
	return (status == Q_IN_DOUBLE_QUOTE && src[i] == '"');
}

bool	is_double_quote_begin(t_q_status status, char *src, size_t i)
{
	return (status == Q_NONE && src[i] == '"');
}

bool	is_single_quote_begin(t_q_status status, char *src, size_t i)
{
	return (status == Q_NONE && src[i] == '\'');
}

void	update_status(t_q_status *status, t_q_status next, size_t *i_p)
{
	*status = next;
	(*i_p)++;
}
