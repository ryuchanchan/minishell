# include "token.h"

static t_token_type	get_token_type(const char *str)
{
	if (ft_strcmp(str, "|") == 0)
		return (T_PIPE);
	if (ft_strcmp(str, "<<") == 0)
		return (T_REDIRECT_HEREDOC);
	if (ft_strcmp(str, "<") == 0)
		return (T_REDIRECT_IN);
	if (ft_strcmp(str, ">>") == 0)
		return (T_REDIRECT_OUT_APPEND);
	if (ft_strcmp(str, ">") == 0)
		return (T_REDIRECT_OUT_TRUNC);
	return (T_WORD);
}

t_token	*construct_token(char *str)
{
	t_token *token_p;

	if (!str)
		return (NULL);
	token_p = malloc(sizeof(t_token));
	if (!token_p)
		return (NULL);
	token_p->str = str;
	token_p->type = get_token_type(token_p->str);
	return (token_p);
}

void	destruct_token(void *content)
{
	t_token *token_p;
	token_p = content;
	if (!token_p)
		return ;
	if (token_p->str)
		free(token_p->str);
	free(token_p);
}
