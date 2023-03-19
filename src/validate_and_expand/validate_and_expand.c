#include "validate_and_expand.h"

static bool	print_quote_error_return_true(void)
{
	ft_putendl_fd(MSG_SYNTAX_ERR_QUOTE, STDERR_FILENO);
	return (true);
}

static bool	print_error_return_true(char *s)
{
	ft_putstr_fd(MSG_SYNTAX_ERR_PREFIX, STDERR_FILENO);
	ft_putstr_fd(s, STDERR_FILENO);
	ft_putendl_fd(MSG_SYNTAX_ERR_SUFFIX, STDERR_FILENO);
	return (true);
}

static void	expand(char **str_p, t_ms_state *state_p)
{
	char	*expanded;

	expanded = expansion(*str_p, state_p);
	if (!expanded)
		fatal_error("expansion");
	free(*str_p);
	*str_p = expanded;
}

bool	validate_and_expand(t_list *tokens, t_ms_state *state_p, bool is_quote_not_closed)
{
	t_list			*list;
	t_token			*t_p;
	t_token_type	type_prev;

	if (is_quote_not_closed)
		return (print_quote_error_return_true());
	type_prev = T_PIPE;
	list = tokens;
	while (list)
	{
		t_p = list->content;
		if (type_prev == T_PIPE && t_p->type == T_PIPE)
			return (print_error_return_true(t_p->str));
		if (is_redirection(type_prev) && t_p->type != T_WORD)
			return (print_error_return_true(t_p->str));
		expand(&(t_p->str), state_p);
		type_prev = t_p->type;
		list = list->next;
	}
	if (type_prev != T_WORD)
		return (print_error_return_true("newline"));
	return (false);
}
