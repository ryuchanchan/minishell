/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:45:49 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:45:53 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_heredoc.h"

void	initialize_heredoc(int tmpin, int tmpout)
{
	safe_dup2(tmpin, STDIN_FILENO, "executor");
	safe_dup2(tmpout, STDOUT_FILENO, "executor");
}

int	do_heredoc(char *str, int tmpin, int tmpout)
{
	int		fd_pipe[2];
	char	*line;

	initialize_heredoc(tmpin, tmpout);
	if (pipe(fd_pipe) < 0)
		fatal_error("executor");
	line = "";
	while (line)
	{
		line = readline(PREFIX_HEREDOC);
		if (!line || ft_strcmp(line, str) == 0 || get_flag() == SF_SIGINT)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd_pipe[1]);
		free(line);
	}
	close(fd_pipe[1]);
	return (fd_pipe[0]);
}
