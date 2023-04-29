/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:45:34 by rykawamu          #+#    #+#             */
/*   Updated: 2023/03/22 22:46:55 by rykawamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"

static bool	is_numerical(char *s)
{
	size_t	i;

	if (!ft_isdigit(s[0]) && s[0] != '+' && s[0] != '-')
		return (false);
	i = 1;
	while (s[i] != '\0')
		if (!ft_isdigit(s[i++]))
			return (false);
	return (true);
}

int	builtin_exit(char **args, char ***envp_p, int exit_status)
{
	int	status;

	(void)envp_p;
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (!args[1])
		exit(exit_status);
	if (!is_numerical(args[1]))
	{
		ft_putstr_fd("exit: ", STDERR_FILENO);
		ft_putstr_fd(args[1], STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		exit(255);
	}
	if (args[2])
	{
		ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
		return (1);
	}
	status = ft_atoi(args[1]);
	exit((unsigned char)status);
	return (0);
}
