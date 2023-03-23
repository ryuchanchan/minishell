/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:41:36 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/22 22:38:56 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_exec.h"

static bool	is_builtin(char *arg_0)
{
	if (!arg_0)
		return (false);
	if (ft_strcmp(arg_0, "echo") == 0)
		return (true);
	if (ft_strcmp(arg_0, "cd") == 0)
		return (true);
	if (ft_strcmp(arg_0, "pwd") == 0)
		return (true);
	if (ft_strcmp(arg_0, "export") == 0)
		return (true);
	if (ft_strcmp(arg_0, "unset") == 0)
		return (true);
	if (ft_strcmp(arg_0, "env") == 0)
		return (true);
	if (ft_strcmp(arg_0, "exit") == 0)
		return (true);
	return (false);
}

static int	do_exec_builtin(char **args, t_ms_state *state_p)
{
	if (ft_strcmp(args[0], "echo") == 0)
		return (builtin_echo(args, &(state_p->envp)));
	if (ft_strcmp(args[0], "cd") == 0)
		return (builtin_cd(args, &(state_p->envp)));
	if (ft_strcmp(args[0], "env") == 0)
		return (builtin_env(args, &(state_p->envp)));
	if (ft_strcmp(args[0], "pwd") == 0)
		return (builtin_pwd(args, &(state_p->envp)));
	if (ft_strcmp(args[0], "export") == 0)
		return (builtin_export(args, &(state_p->envp)));
	if (ft_strcmp(args[0], "unset") == 0)
		return (builtin_unset(args, &(state_p->envp)));
	if (ft_strcmp(args[0], "exit") == 0)
		return (builtin_exit(args, &(state_p->envp), state_p->exit_status));
	return (-1);
}

static void	do_exec_fork(t_command *c_p, char **args, t_ms_state *state_p)
{
	char	*path_resolved;

	c_p->pid = fork();
	if (c_p->pid == 0)
	{
		if (is_builtin(args[0]))
			exit(do_exec_builtin(args, state_p));
		path_resolved = resolve_filename(args[0], &(state_p->envp));
		if (!path_resolved)
			fatal_error("executor");
		execve(path_resolved, args, state_p->envp);
		free(path_resolved);
		fatal_error(args[0]);
	}
	if (c_p->pid < 0)
		fatal_error("executor");
}

void	do_exec(t_command *c_p, t_ms_state *state_p, bool is_piped)
{
	char	**args;

	if (!c_p->args)
		return ;
	args = sa_from_list(c_p->args);
	if (!args)
		fatal_error("executor");
	if (!is_piped && is_builtin(args[0]))
		c_p->status = do_exec_builtin(args, state_p);
	else
		do_exec_fork(c_p, args, state_p);
	free(args);
}
