/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirect.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:12:18 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:12:20 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_REDIRECT_H
# define DO_REDIRECT_H

# include <fcntl.h>

# include "command.h"
# include "ms_error.h"
# include "do_heredoc.h"

# define PERMISSION 0644

bool	do_redirect(t_list *command, int fdin, int tmpin, int tmpout);

#endif
