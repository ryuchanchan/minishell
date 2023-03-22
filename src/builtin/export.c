/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:16:52 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/22 22:44:58 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"

static bool	is_invalid_name(char *str)
{
	size_t	i;

	if (!str || str[0] == '\0' || str[0] == '=')
		return (true);
	i = 0;
	while (str[i] != '\0' && str[i] != '=')
	{
		if (i == 0 && ft_isdigit(str[0]))
			return (true);
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (true);
		i++;
	}
	return (false);
}

static int	print_setted(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "_=", 2) != 0)
			ft_printf("declare -x %s\n", envp[i]);
		i++;
	}
	return (0);
}

static void	export_one(char *arg, char ***envp_p, int *status_p)
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
	if (!ft_strchr(arg, '=') || ft_strncmp(arg, "_=", 2) == 0)
		return ;
	kv_p = construct_kv(arg);
	if (!kv_p)
		fatal_error("export");
	env_add(envp_p, kv_p);
	destruct_kv(&kv_p);
	return ;
}

int	builtin_export(char **args, char ***envp_p)
{
	int		status;
	size_t	i;

	if (!args[1])
		return (print_setted(*envp_p));
	status = 0;
	i = 1;
	while (args[i])
		export_one(args[i++], envp_p, &status);
	return (status);
}
