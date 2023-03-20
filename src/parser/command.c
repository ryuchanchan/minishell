/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 01:20:10 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 01:20:12 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

t_command	*construct_command(void)
{
	t_command	*command_p;

	command_p = malloc(sizeof(t_command));
	if (!command_p)
		return (NULL);
	command_p->args = NULL;
	command_p->redirections = NULL;
	command_p->pid = 0;
	command_p->status = 0;
	return (command_p);
}

void	destruct_command(void *content)
{
	t_command	*command_p;

	if (!content)
		return ;
	command_p = content;
	if (command_p->args)
		ft_lstclear(&(command_p->args), free);
	if (command_p->redirections)
		ft_lstclear(&(command_p->redirections), destruct_redirection);
	command_p->pid = 0;
	command_p->status = 0;
	free(command_p);
}
