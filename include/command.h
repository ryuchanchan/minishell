/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:12:37 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:12:39 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "redirection.h"

typedef struct s_command
{
	t_list			*args;
	t_list			*redirections;
	pid_t			pid;
	int				status;
}	t_command;

t_command	*construct_command(void);
void		destruct_command(void *content);

#endif
