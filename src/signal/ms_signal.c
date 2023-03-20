/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 01:27:35 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 01:28:52 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_signal.h"

static void	signal_interrupt_handler(int sig)
{
	if (sig != SIGINT)
		return ;
	set_flag(SF_SIGINT);
}

static void	signal_quit_handler(int sig)
{
	if (sig != SIGQUIT)
		return ;
	if (get_flag() == SF_NONE)
		set_flag(SF_SIGQUIT);
	rl_redisplay();
}

void	set_signal(void)
{
	signal(SIGINT, signal_interrupt_handler);
	signal(SIGQUIT, signal_quit_handler);
}
