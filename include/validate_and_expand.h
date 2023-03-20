/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_expand.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:10:24 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:10:25 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_AND_EXPAND_H
# define VALIDATE_AND_EXPAND_H

# include "ms_error.h"
# include "ms_state.h"
# include "expansion.h"

bool	check_and_expand(t_list *tokens, t_ms_state *state, bool is_open_quote);

#endif
