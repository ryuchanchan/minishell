/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 01:20:44 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 01:20:49 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

t_redirection	*construct_redirection(t_token *token_p, t_token *next_p)
{
	t_redirection	*redirection_p;

	redirection_p = malloc(sizeof(t_redirection));
	if (!redirection_p)
		return (NULL);
	redirection_p->type = token_p->type;
	redirection_p->filename = NULL;
	if (next_p->str)
		redirection_p->filename = ft_strdup(next_p->str);
	if (!redirection_p->filename)
	{
		free(redirection_p);
		return (NULL);
	}
	return (redirection_p);
}

void	destruct_redirection(void *content)
{
	t_redirection	*redirection_p;

	if (!content)
		return ;
	redirection_p = content;
	if (redirection_p->filename)
		free(redirection_p->filename);
	free(redirection_p);
}

bool	is_redirection(t_token_type type)
{
	if (type == T_REDIRECT_HEREDOC || type == T_REDIRECT_IN)
		return (true);
	if (type == T_REDIRECT_OUT_TRUNC || type == T_REDIRECT_OUT_APPEND)
		return (true);
	return (false);
}
