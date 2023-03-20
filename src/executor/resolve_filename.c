/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_filename.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:42:31 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:42:34 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolve_filename.h"

static char	*concat_path(char *path, char *filename)
{
	size_t	len;
	char	*tmp;
	char	*joined;

	if (!path || !filename)
		return (NULL);
	len = ft_strlen(path);
	if (len == 0)
		return (ft_strdup(filename));
	if (path[len - 1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		joined = ft_strjoin(tmp, filename);
		free(tmp);
		return (joined);
	}
	return (ft_strjoin(path, filename));
}

static void	exit_with_print(char *command, char *msg, int exit_status)
{
	ft_putstr_fd(command, STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(exit_status);
}

static char	*find_exist_path(char *command, char *str_paths)
{
	size_t	i;
	char	**paths;
	char	*exist_path;

	paths = ft_split(str_paths, ':');
	if (!paths)
		fatal_error("resolve_filename");
	i = 0;
	while (paths[i])
	{
		exist_path = concat_path(paths[i], command);
		if (!exist_path)
			fatal_error("resolve_filename");
		if (is_regular_file(exist_path))
			break ;
		free(exist_path);
		exist_path = NULL;
		i++;
	}
	sa_free(paths);
	return (exist_path);
}

static char	*resolve_filename_with_path(char *command, char ***envp_p)
{
	t_kv	*kv_path;
	char	*filepath;

	kv_path = env_find((const char **)*envp_p, "PATH");
	if (!kv_path)
	{
		filepath = concat_path("./", command);
		if (!filepath)
			fatal_error("resolve_filename");
		if (is_directory(filepath))
			exit_with_print(command, MSG_IS_DIRECTORY, STAT_IS_DIRECTORY);
		return (filepath);
	}
	filepath = find_exist_path(command, kv_path->value);
	destruct_kv(&kv_path);
	if (!filepath)
		exit_with_print(command, MSG_CMD_NOT_FOUND, STAT_CMD_NOT_FOUND);
	return (filepath);
}

char	*resolve_filename(char *arg_0, char ***envp_p)
{
	char	*dupped;

	if (ft_strchr(arg_0, '/'))
	{
		if (is_directory(arg_0))
			exit_with_print(arg_0, MSG_IS_DIRECTORY, STAT_IS_DIRECTORY);
		dupped = ft_strdup(arg_0);
		if (!dupped)
			fatal_error("resolve_filename");
		return (dupped);
	}
	return (resolve_filename_with_path(arg_0, envp_p));
}
