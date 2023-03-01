/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:01:10 by toryoshi          #+#    #+#             */
/*   Updated: 2022/04/20 15:42:39 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s_uc;

	s_uc = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s_uc[i] == (unsigned char)c)
			return ((void *)(&s_uc[i]));
		i++;
	}
	return (NULL);
}
