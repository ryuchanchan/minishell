/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:42:35 by rykawamu          #+#    #+#             */
/*   Updated: 2023/03/23 13:45:06 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"

int	builtin_pwd(char **args, char ***envp_p)
{
	char	buf[PATH_MAX + 1];

	(void)envp_p;
	(void)args;
	if (getcwd(buf, PATH_MAX + 1) == NULL)
	{
		perror("pwd");
		return (1);
	}
	ft_putendl_fd(buf, STDOUT_FILENO);
	return (0);
}
