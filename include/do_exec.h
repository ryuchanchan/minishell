/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:13:46 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:13:50 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_EXEC_H
# define DO_EXEC_H

# include "ms_error.h"
# include "command.h"
# include "string_array.h"
# include "ms_state.h"
# include "ms_builtin.h"
# include "resolve_filename.h"

void	do_exec(t_command *c_p, t_ms_state *state_p, bool is_piped);

#endif
