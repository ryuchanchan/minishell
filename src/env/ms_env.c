/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:39:09 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:39:11 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_env.h"

static ssize_t	env_get_index(const char **envp, const char *key)
{
	size_t	i;
	t_kv	*kv_p;

	if (!envp || !key)
		return (-1);
	i = 0;
	while (envp[i])
	{
		kv_p = construct_kv(envp[i]);
		if (!kv_p)
			fatal_error("env");
		if (ft_strcmp(kv_p->key, key) == 0)
		{
			destruct_kv(&kv_p);
			return (i);
		}
		destruct_kv(&kv_p);
		i++;
	}
	return (-1);
}

t_kv	*env_find(const char **envp, const char *key)
{
	ssize_t	index;
	t_kv	*kv_p;

	index = env_get_index(envp, key);
	if (index < 0)
		return (NULL);
	kv_p = construct_kv(envp[index]);
	if (!kv_p)
		fatal_error("env");
	return (kv_p);
}

static void	update_envp(char ***envp_p, char *str, size_t size)
{
	size_t	i;
	char	**new;

	new = malloc(sizeof(char *) * (size + 1));
	if (!new)
		fatal_error("env");
	i = 0;
	while ((*envp_p)[i])
	{
		new[i] = (*envp_p)[i];
		i++;
	}
	new[size - 2] = str;
	new[size - 1] = (*envp_p)[i - 1];
	new[size] = NULL;
	free(*envp_p);
	*envp_p = new;
}

void	env_add(char ***envp_p, t_kv *kv_p)
{
	ssize_t	index;
	char	*str;

	str = kv_to_string(kv_p);
	if (!str)
		fatal_error("env");
	index = env_get_index((const char **)*envp_p, (const char *)kv_p->key);
	if (index >= 0)
	{
		free((*envp_p)[index]);
		(*envp_p)[index] = str;
		return ;
	}
	update_envp(envp_p, str, sa_size((const char **)(*envp_p)));
}

void	env_delete(char ***envp_p, char *key)
{
	ssize_t	i;
	ssize_t	index;
	ssize_t	size;
	char	**new;

	index = env_get_index((const char **)*envp_p, key);
	if (index < 0)
		return ;
	size = sa_size((const char **)*envp_p);
	new = malloc(sizeof(char *) * (size - 1));
	if (!new)
		fatal_error("env");
	free((*envp_p)[index]);
	i = 0;
	while ((*envp_p)[i])
	{
		if (i < index)
			new[i] = (*envp_p)[i];
		else
			new[i] = (*envp_p)[i + 1];
		i++;
	}
	free(*envp_p);
	*envp_p = new;
}
