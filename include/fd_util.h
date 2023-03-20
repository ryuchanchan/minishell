/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_util.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 02:57:30 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 02:57:35 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_UTIL_H
# define FD_UTIL_H

# include <unistd.h>

# include "ms_error.h"

void	safe_dup2(int fildes, int fildes2, char *msg_err);

#endif
