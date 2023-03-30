/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 01:26:25 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 01:26:53 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_flag.h"

static volatile t_signal_flag	g_flag;

void	reset_flag(void)
{
	g_flag = SF_NONE;
}

t_signal_flag	get_flag(void)
{
	return (g_flag);
}

void	set_flag(t_signal_flag new)
{
	if (new == SF_NONE || new == SF_SIGINT)
	{
		g_flag = new;
		return ;
	}
	if (g_flag != SF_NONE)
		return ;
	if (new == SF_SIGQUIT)
		g_flag = new;
}

bool	has_signal_interrupt(void)
{
	return (g_flag == SF_SIGINT || g_flag == SF_SIGQUIT);
}
