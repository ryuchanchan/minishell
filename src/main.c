/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 01:41:21 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 03:00:06 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_state(void)
{
	if (get_flag() == SF_SIGINT)
		rl_done = true;
	return (0);
}

static void	initialize(t_ms_state **state_p, char **envp)
{
	*state_p = malloc(sizeof(t_ms_state));
	if (!*state_p)
		fatal_error("initialize");
	(*state_p)->exit_status = 0;
	(*state_p)->envp = sa_clone((const char **)envp);
	if (!(*state_p)->envp)
		fatal_error("initialize");
	set_signal();
	rl_event_hook = check_state;
}

static int	finalize(t_ms_state *state_p)
{
	int	status;

	status = state_p->exit_status;
	destruct_ms_state(state_p);
	rl_clear_history();
	ft_printf("exit\n");
	return (status);
}

int	main(int argc, char **argv, char **envp)
{
	t_ms_state	*state_p;

	(void)argc;
	(void)argv;
	initialize(&state_p, envp);
	minishell(state_p);
	return (finalize(state_p));
}
