/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:36:50 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:36:52 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"

static void	print_array(char **splitted, const size_t begin)
{
	size_t	i;

	i = begin;
	while (splitted[i])
	{
		ft_putstr_fd(splitted[i], STDOUT_FILENO);
		if (splitted[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
}

int	builtin_echo(char **args, char ***envp_p)
{
	size_t	i;

	(void)envp_p;
	i = 1;
	while (args[i] && ft_strcmp(args[i], "-n") == 0)
		i++;
	if (args[i])
		print_array(args, i);
	if (i == 1)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
