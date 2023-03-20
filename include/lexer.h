/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:04:48 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:04:56 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdio.h>
# include <fcntl.h>

# include "quotes.h"
# include "token.h"
# include "ms_error.h"

typedef struct s_lexer
{
	char		*start;
	t_q_status	status;
}	t_lexer;

t_list	*lexer(char *input, bool *is_open_quote_p);

#endif
