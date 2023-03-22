/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:47:26 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/22 22:48:57 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"

static bool	is_invalid_name(char *str)
{
	size_t	i;

	if (!str || str[0] == '\0')
		return (true);
	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && ft_isdigit(str[0]))
			return (true);
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (true);
		i++;
	}
	return (false);
}

static void	unset_one(char *arg, char ***envp_p, int *status_p)
{
	t_kv	*kv_p;

	if (is_invalid_name(arg))
	{
		ft_putstr_fd("export: `", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
		*status_p = 1;
		return ;
	}
	if (ft_strcmp(arg, "_") == 0)
		return ;
	kv_p = env_find((const char **)*envp_p, arg);
	if (!kv_p)
		return ;
	env_delete(envp_p, kv_p->key);
	destruct_kv(&kv_p);
}

int	builtin_unset(char **args, char ***envp_p)
{
	int		status;
	size_t	i;

	status = 0;
	i = 1;
	while (args[i])
		unset_one(args[i++], envp_p, &status);
	return (status);
}
