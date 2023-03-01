/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:17:40 by toryoshi          #+#    #+#             */
/*   Updated: 2022/04/26 16:23:35 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	len_s;
	size_t	div;
	int		mod;

	if (s == NULL)
		return ;
	len_s = ft_strlen(s);
	if (len_s == 0)
		return ;
	div = len_s / INT_MAX;
	mod = len_s % INT_MAX;
	i = 0;
	while (i < div)
		write(fd, &s[INT_MAX * i++], INT_MAX);
	write(fd, &s[INT_MAX * i], mod);
}
