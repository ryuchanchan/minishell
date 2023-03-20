/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 01:30:05 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 01:30:07 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_util.h"

bool	is_directory(char *filepath)
{
	struct stat	buf;

	if (lstat(filepath, &buf) != 0)
		return (false);
	return (S_ISDIR(buf.st_mode));
}

bool	is_regular_file(char *filepath)
{
	struct stat	buf;

	if (lstat(filepath, &buf) != 0)
		return (false);
	return (S_ISREG(buf.st_mode));
}
