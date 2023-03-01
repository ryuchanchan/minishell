/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:26:30 by toryoshi          #+#    #+#             */
/*   Updated: 2022/05/27 03:32:51 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_queue(char *queue)
{
	if (queue)
		free(queue);
	return (NULL);
}

static char	*dequeue(char **queue_p, char *pos_nl)
{
	size_t	size;
	char	*next_line;
	char	*queue_old;

	queue_old = *queue_p;
	if (!pos_nl)
	{
		next_line = ft_strndup(*queue_p, ft_strlen(*queue_p));
		if (!next_line)
			return (free_queue(queue_old));
		*queue_p = NULL;
		free(queue_old);
		return (next_line);
	}
	size = (size_t)(pos_nl - *queue_p + 1);
	next_line = ft_strndup(*queue_p, size);
	if (!next_line)
		return (free_queue(queue_old));
	*queue_p = ft_strndup(pos_nl + 1, ft_strlen(pos_nl + 1));
	free(queue_old);
	if (!*queue_p)
		return (free_queue(next_line));
	return (next_line);
}

static char	*enqueue(char *queue, char *buf)
{
	char	*joined;
	char	*queue_old;

	joined = ft_strjoin(queue, buf);
	queue_old = queue;
	free(queue_old);
	return (joined);
}

static char	*read_line(int fd, char **buf_p, char **queue_p)
{
	ssize_t	size_buf;
	char	*next_line;
	char	*pos_nl;

	size_buf = 1;
	pos_nl = NULL;
	while (pos_nl == NULL && size_buf != 0)
	{
		size_buf = read(fd, *buf_p, BUFFER_SIZE);
		if (size_buf == -1)
			return (free_queue(*queue_p));
		(*buf_p)[size_buf] = '\0';
		*queue_p = enqueue(*queue_p, *buf_p);
		if (!*queue_p)
			return (NULL);
		pos_nl = ft_strchr(*queue_p, '\n');
	}
	next_line = dequeue(queue_p, pos_nl);
	if (size_buf == 0 && next_line && ft_strlen(next_line) == 0)
	{
		free(next_line);
		return (NULL);
	}
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*queue;
	char		*next_line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || (size_t)BUFFER_SIZE > INT_MAX)
		return (NULL);
	buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buf)
		return (free_queue(queue));
	next_line = read_line(fd, &buf, &queue);
	free(buf);
	return (next_line);
}
