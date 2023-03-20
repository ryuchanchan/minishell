/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:16:16 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:16:18 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ms_signal.h"
# include "ms_error.h"
# include "ms_state.h"
# include "lexer.h"
# include "parser.h"
# include "executor.h"
# include "expansion.h"
# include "validate_and_expand.h"

# define PREFIX_SHELL "minishell> "

#endif
