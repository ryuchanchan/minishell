#include "expansion.h"

static bool should_replace_var(t_status_quotes status, const char *src, size_t i)
{
	if (status == IN_SINGLE_QUOTE || src[i] != '$')
		return (false);
	if (src[i + 1] == '"' && status != IN_DOUBLE_QUOTE)
		return (true);
	if (src[i + 1] == '\'')
		return (true);
	return (src[i + 1] == '?' || src[i + 1] == '_' || ft_isalpha(src[i + 1]));
}

char	*expansion(const char *src)
{
	t_expansions ex;

	ex.src = src;
	ex.dest = ft_strdup(src);
	if (!ex.dest)
		return(NULL);
	ex.status = NONE;
	ex.i = 0;
	ex.j = 0;
	while (ex.src[ex.i] != '\0')
		if (should_replace_var(ex.status, ex.src, ex.i))
			replace_var(&ex);
		else if (is_single_quote_begin(ex.status, ex.src, ex.i))
			update_status(&(ex.status), IN_SINGLE_QUOTE, &(ex.i));
		else if (is_double_quote_begin(ex.status, ex.src, ex.i))
			update_status(&(ex.status), IN_DOUBLE_QUOTE, &(ex.i));
		else if (is_quote_end(ex.status, ex.src, ex.i))
			update_status(&(ex.status), NONE, &(ex.i));
		else
			ex.dest[ex.j++] = ex.src[ex.i++];
	ex.dest[ex.j] = '\0';
	return (ex.dest);
}
