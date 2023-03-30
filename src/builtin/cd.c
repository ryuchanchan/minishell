/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rykawamu </var/mail/rykawamu>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:40:12 by rykawamu          #+#    #+#             */
/*   Updated: 2023/03/23 13:46:42 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtin.h"

static void	env_set(char *key, char *value, char ***envp_p)
{
	char	*tmp;
	char	*joined;
	t_kv	*kv_p;

	tmp = ft_strjoin(key, "=");
	if (!tmp)
		fatal_error("cd");
	joined = ft_strjoin(tmp, value);
	free(tmp);
	if (!joined)
		fatal_error("cd");
	kv_p = construct_kv(joined);
	free(joined);
	if (!kv_p)
		fatal_error("cd");
	env_add(envp_p, kv_p);
	destruct_kv(&kv_p);
}

static char	*get_pwd(char **envp)
{
	t_kv	*kv_p;
	char	*dupped;

	kv_p = env_find((const char **)envp, "PWD");
	if (!kv_p)
		return (ft_strdup(""));
	else
	{
		dupped = ft_strdup(kv_p->value);
		destruct_kv(&kv_p);
		return (dupped);
	}
}

static int	cd_without_arg(char **envp)
{
	t_kv	*kv_p;

	kv_p = env_find((const char **)envp, "HOME");
	if (!kv_p)
	{
		ft_putendl_fd("cd: HOME not set", STDERR_FILENO);
		return (1);
	}
	if (chdir(kv_p->value) == -1)
	{
		perror("cd");
		destruct_kv(&kv_p);
		return (1);
	}
	destruct_kv(&kv_p);
	return (0);
}

static int	cd_with_arg(char *arg)
{
	if (chdir(arg) == -1)
	{
		perror("cd");
		return (1);
	}
	return (0);
}

int	builtin_cd(char **args, char ***envp_p)
{
	int		ret;
	char	*oldpwd;
	char	buf_pwd[PATH_MAX + 1];

	oldpwd = get_pwd(*envp_p);
	if (!args[1])
		ret = cd_without_arg(*envp_p);
	else
		ret = cd_with_arg(args[1]);
	if (ret == 0 || getcwd(buf_pwd, PATH_MAX + 1))
	{
		env_set("OLDPWD", oldpwd, envp_p);
		env_set("PWD", buf_pwd, envp_p);
	}
	free(oldpwd);
	return (ret);
}
