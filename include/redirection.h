/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:12:00 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:12:01 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "token.h"

typedef struct s_redirection
{
	t_token_type	type;
	char			*filename;
}	t_redirection;

t_redirection	*construct_redirection(t_token *token_p, t_token *next_p);
void			destruct_redirection(void *content);

#endif
