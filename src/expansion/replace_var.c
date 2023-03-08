#include "expansion.h"

static char *get_name(const char *src, size_t *i)
{
	size_t start;

	if (ft_isdigit(src[*i]) || src[*i] == '?')
	{
		(*i)++;
		return ft_strndup(&src[*i - 1], 1);
	}
	if ((src[*i] == '"' || src[*i] == '\''))
	{
		(*i)++;
		return ft_strdup("");
	}
	start = *i;
	while (src[*i] == '_' || ft_isalnum(src[*i]))
		(*i)++;
	return (ft_strndup(&src[start], *i - start));
}

static char *get_val(const char *name)
{
	char	*val;
	if (ft_strcmp(name, "?") == 0)
	{
		return (ft_strdup("{state_result}"));// Todo implements
	}
	val = getenv(name);
	if (!val)
		return (ft_strdup(""));
	return (ft_strdup(val));
}

static void	join_strs(char *before, char *val, char *after, t_expansions *ex)
{
	char *tmp;

	tmp = ft_strjoin(before, val);
	if (!tmp)
		exit(1);
	ex->j = ft_strlen(tmp);
	free(ex->dest);
	ex->dest = ft_strjoin(tmp, after);
	free(tmp);
}

void replace_var(t_expansions *ex)
{
	char *before;
	char *name;
	char *val;
	char *after;

	ex->i++;
	ex->dest[ex->j] = '\0';
	before = ft_strdup(ex->dest);
	name = get_name(ex->src, &(ex->i));
	after = ft_strdup(&ex->src[ex->i]);
	if (!before || !name || !after)
		exit(1);
	val = get_val(name);
	if (!val)
		exit(1);
	join_strs(before, val, after, ex);
	free(before);
	free(name);
	free(val);
	free(after);
	if (!ex->dest)
		exit(1);
}
