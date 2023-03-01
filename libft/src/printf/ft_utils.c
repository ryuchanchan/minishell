/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:38:50 by toryoshi          #+#    #+#             */
/*   Updated: 2022/05/15 00:38:52 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_overlimit(int n, int count)
{
	return (n >= INT_MAX - count);
}

void	ft_putstrn_fd(char *s, size_t n, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, n);
}
