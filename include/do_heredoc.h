/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_heredoc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:15:30 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:15:33 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_HEREDOC_H
# define DO_HEREDOC_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "command.h"
# include "ms_error.h"
# include "signal_flag.h"

# define PREFIX_HEREDOC "heredoc> "

int	do_heredoc(char *str, int tmpin, int tmpout);

#endif
