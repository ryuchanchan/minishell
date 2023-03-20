/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 01:14:53 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 01:19:16 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	add_token(char *s, char *start, t_list **list_p)
{
	t_token	*token_p;
	t_list	*list;
	size_t	n;

	if (s == start)
		return ;
	n = (s - start) / sizeof(char);
	token_p = construct_token(ft_strndup(start, n));
	if (!token_p)
		fatal_error("lexer");
	list = ft_lstnew(token_p);
	if (!list)
		fatal_error("lexer");
	ft_lstadd_back(list_p, list);
}

static void	extract(char *line, size_t *i_p, char **start_p, t_list **tokens_p)
{
	add_token(&line[*i_p], *start_p, tokens_p);
	*start_p = &line[*i_p + 1];
	if (line[*i_p] == ' ' || line[*i_p] == '\t')
	{
		(*i_p)++;
		return ;
	}
	if (ft_strncmp(&line[*i_p], "<<", 2) == 0 \
			|| ft_strncmp(&line[*i_p], ">>", 2) == 0)
	{
		add_token(&line[*i_p + 2], &line[*i_p], tokens_p);
		*start_p = &line[*i_p + 2];
		*i_p += 2;
		return ;
	}
	add_token(&line[*i_p + 1], &line[*i_p], tokens_p);
	(*i_p)++;
}

static bool	is_separator(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	return (c == '|' || c == '<' || c == '>');
}

static void	initialize_lexer(t_lexer *lexer_p, char *line)
{
	lexer_p->start = line;
	lexer_p->status = Q_NONE;
}

t_list	*lexer(char *line, bool *is_quote_not_closed_p)
{
	size_t	i;
	t_lexer	lexer;
	t_list	*tokens;

	initialize_lexer(&lexer, line);
	tokens = NULL;
	i = 0;
	while (line[i] != '\0')
	{
		if (is_single_quote_begin(lexer.status, line, i))
			update_status(&lexer.status, Q_IN_SINGLE_QUOTE, &i);
		else if (is_double_quote_begin(lexer.status, line, i))
			update_status(&lexer.status, Q_IN_DOUBLE_QUOTE, &i);
		else if (is_quote_end(lexer.status, line, i))
			update_status(&lexer.status, Q_NONE, &i);
		else if (is_separator(line[i]) && lexer.status == Q_NONE)
			extract(line, &i, &lexer.start, &tokens);
		else
			i++;
	}
	add_token(&line[i], lexer.start, &tokens);
	if (lexer.status != Q_NONE)
		*is_quote_not_closed_p = true;
	return (tokens);
}
