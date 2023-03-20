/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_stat.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:13:24 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:13:26 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_STAT_H
# define FILE_STAT_H

# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>

bool	is_directory(char *filepath);
bool	is_regular_file(char *filepath);

#endif
