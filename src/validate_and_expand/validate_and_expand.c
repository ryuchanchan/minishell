#include "validate_and_expand.h"

static bool	quote_error_return_true(void)
{
	print_quote_error();
	return (true);
}

static bool	syntax_error_return_true(char *s)
{
	print_syntax_error(s);
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

bool	check_and_expand(t_list *tokens, t_ms_state *state_p, bool is_open_quote)
{
	t_list			*list;
	t_token			*t_p;
	t_token_type	type_prev;

	if (is_open_quote)
		return (quote_error_return_true());
	type_prev = T_PIPE;
	list = tokens;
	while (list)
	{
		t_p = list->content;
		if (type_prev == T_PIPE && t_p->type == T_PIPE)
			return (syntax_error_return_true(t_p->str));
		if (is_redirection(type_prev) && t_p->type != T_WORD)
			return (syntax_error_return_true(t_p->str));
		expand(&(t_p->str), state_p);
		type_prev = t_p->type;
		list = list->next;
	}
	if (type_prev != T_WORD)
		return (syntax_error_return_true("newline"));
	return (false);
}
