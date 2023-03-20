/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:39:32 by toryoshi          #+#    #+#             */
/*   Updated: 2023/03/21 00:39:34 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_error.h"

void	fatal_error(char *str)
{
	perror(str);
	exit(STAT_FATAL_ERR);
}

void	print_quote_error(void)
{
	ft_putendl_fd(MSG_SYNTAX_ERR_QUOTE, STDERR_FILENO);
}

void	print_syntax_error(char *str)
{
	ft_putstr_fd(MSG_SYNTAX_ERR_PREFIX, STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putendl_fd(MSG_SYNTAX_ERR_SUFFIX, STDERR_FILENO);
}
