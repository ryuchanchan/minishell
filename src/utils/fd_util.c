/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 03:00:31 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 03:00:36 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_util.h"

void	safe_dup2(int fildes, int fildes2, char *msg_err)
{
	if (dup2(fildes, fildes2) < 0)
		fatal_error(msg_err);
}
