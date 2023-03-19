#include "expansion.h"

static char	*get_name(const char *src, size_t *i)
{
	size_t	start;

	if (ft_isdigit(src[*i]) || src[*i] == '?')
	{
		(*i)++;
		return (ft_strndup(&src[*i - 1], 1));
	}
	if ((src[*i] == '"' || src[*i] == '\''))
	{
		(*i)++;
		return (ft_strdup(""));
	}
	start = *i;
	while (src[*i] == '_' || ft_isalnum(src[*i]))
		(*i)++;
	return (ft_strndup(&src[start], *i - start));
}

static char	*get_val(const char *name, t_ms_state *state_p)
{
	char	*val;
	t_kv	*kv;

	if (ft_strcmp(name, "?") == 0)
		return (ft_itoa(state_p->exit_status));
	kv = env_find((const char **)state_p->envp, name);
	if (!kv)
		return (ft_strdup(""));
	val = ft_strdup(kv->value);
	destruct_kv(&kv);
	return (val);
}

static void	join_strs(char *before, char *val, char *after, t_expansions *ex)
{
	char	*tmp;

	tmp = ft_strjoin(before, val);
	if (!tmp)
		fatal_error("expansion");
	ex->j = ft_strlen(tmp);
	free(ex->dest);
	ex->dest = ft_strjoin(tmp, after);
	free(tmp);
}

void	replace_var(t_expansions *ex, t_ms_state *state_p)
{
	char	*before;
	char	*name;
	char	*val;
	char	*after;

	ex->i++;
	ex->dest[ex->j] = '\0';
	before = ft_strdup(ex->dest);
	name = get_name(ex->src, &(ex->i));
	after = ft_strdup(&ex->src[ex->i]);
	if (!before || !name || !after)
		fatal_error("expansion");
	val = get_val(name, state_p);
	if (!val)
		fatal_error("expansion");
	join_strs(before, val, after, ex);
	free(before);
	free(name);
	free(val);
	free(after);
	if (!ex->dest)
		fatal_error("expansion");
}
