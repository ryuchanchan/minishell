/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:43:49 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:43:53 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	initialize_fds(int *tmpin_p, int *tmpout_p)
{
	*tmpin_p = dup(STDIN_FILENO);
	if (*tmpin_p < 0)
		fatal_error("executor");
	*tmpout_p = dup(STDOUT_FILENO);
	if (*tmpout_p < 0)
		fatal_error("executor");
}

static void	finalize_fds(int tmpin, int tmpout)
{
	safe_dup2(tmpin, STDIN_FILENO, "executor");
	safe_dup2(tmpout, STDOUT_FILENO, "executor");
	close(tmpin);
	close(tmpout);
}

static int	get_exit_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	return (-1);
}

static int	wait_childs(t_list *commands, bool is_piped)
{
	t_list		*command;
	t_command	*c_p;
	int			status;

	status = 0;
	command = commands;
	while (command)
	{
		c_p = command->content;
		if (c_p->pid > 0)
			if (waitpid(c_p->pid, &(c_p->status), 0) < 0)
				fatal_error("executor");
		if (!command->next)
		{
			if (c_p->pid == 0 && !is_piped)
				status = c_p->status;
			else
				status = get_exit_status(c_p->status);
		}
		command = command->next;
	}
	return (status);
}

int	executor(t_list *commands, t_ms_state *state_p)
{
	t_list	*command;
	int		fdin;
	bool	is_piped;

	initialize_fds(&state_p->tmpin, &state_p->tmpout);
	fdin = dup(state_p->tmpin);
	command = commands;
	is_piped = (command->next != NULL);
	while (command)
	{
		if (do_redirect(command, fdin, state_p->tmpin, state_p->tmpout))
		{
			if (get_flag() == SF_SIGINT)
			{
				finalize_fds(state_p->tmpin, state_p->tmpout);
				return (1);
			}
			command = command->next;
			continue ;
		}
		do_exec(command->content, state_p, is_piped);
		command = command->next;
	}
	finalize_fds(state_p->tmpin, state_p->tmpout);
	return (wait_childs(commands, is_piped));
}
