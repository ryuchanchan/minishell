/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_flag.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:18:48 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:20:21 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_FLAG_H
# define SIGNAL_FLAG_H

# include <stdbool.h>

typedef enum e_signal_flag
{
	SF_NONE,
	SF_SIGINT,
	SF_SIGQUIT
}	t_signal_flag;

void			reset_flag(void);
t_signal_flag	get_flag(void);
void			set_flag(t_signal_flag new_flag);
bool			has_signal_interrupt(void);

#endif
