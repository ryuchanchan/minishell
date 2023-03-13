#include "quotes.h"

bool	is_quote_end(const t_status_quotes status, const char *src, size_t i)
{
	if (status == IN_SINGLE_QUOTE && src[i] == '\'')
		return (true);
	return (status == IN_DOUBLE_QUOTE && src[i] == '"');
}

bool	is_double_quote_begin(const t_status_quotes status, const char *src, size_t i)
{
	return (status == NONE && src[i] == '"');
}

bool	is_single_quote_begin(const t_status_quotes status, const char *src, size_t i)
{
	return (status == NONE && src[i] == '\'');
}

void	update_status(t_status_quotes *status, t_status_quotes next, size_t *i_p)
{
	*status = next;
	(*i_p)++;
}
