/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_filename.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:18:08 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:18:10 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLVE_FILENAME_H
# define RESOLVE_FILENAME_H

# include "ms_error.h"
# include "ms_env.h"
# include "file_stat.h"
# include "string_array.h"
# include "key_value.h"

char	*resolve_filename(char *arg_0, char ***envp_p);

#endif
