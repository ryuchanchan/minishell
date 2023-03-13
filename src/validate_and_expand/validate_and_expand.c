#include "validate_and_expand.h"

static bool	print_error_return_true(char *s)
{
	ft_putstr_fd(MSG_SYNTAX_ERR_PREFIX, STDERR_FILENO);
	ft_putstr_fd(s, STDERR_FILENO);
	ft_putendl_fd(MSG_SYNTAX_ERR_SUFFIX, STDERR_FILENO);
	return (true);
}

static void	expand(char **str_p)
{
	char	*expanded;

	expanded = expansion(*str_p);
		if (!expanded)
			exit(1);
	free(*str_p);
	*str_p = expanded;
}

bool	validate_and_expand(t_list *tokens)
{
	t_list			*list;
	t_token			*t_p;
	t_token_type	type_prev;

	type_prev = T_PIPE;
	list = tokens;
	while (list)
	{
		t_p = list->content;
		if (type_prev == T_PIPE && t_p->type == T_PIPE)
			return (print_error_return_true(t_p->str));
		if (is_redirection(type_prev) && t_p->type != T_WORD)
			return (print_error_return_true(t_p->str));
		expand(&(t_p->str));
		type_prev = t_p->type;
		list = list->next;
	}
	if (type_prev != T_WORD)
		return (print_error_return_true("newline"));
	return (false);
}
