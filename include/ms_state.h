/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_state.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:06:45 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:07:23 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_STATE_H
# define MS_STATE_H

# include "string_array.h"

typedef struct s_ms_state
{
	char	**envp;
	int		exit_status;
	int		tmpin;
	int		tmpout;
}	t_ms_state;

t_ms_state	*construct_ms_state(char **envp);
void		destruct_ms_state(t_ms_state *state_p);

#endif
