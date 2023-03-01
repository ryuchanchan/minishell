/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:49:33 by toryoshi          #+#    #+#             */
/*   Updated: 2022/04/08 01:14:50 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*src_uc;
	unsigned char		*dst_uc;
	size_t				i;

	src_uc = (const unsigned char *)src;
	dst_uc = (unsigned char *)dst;
	if (dst_uc == src_uc)
		return (dst);
	i = 0;
	while (i < n)
	{
		dst_uc[i] = src_uc[i];
		i++;
	}
	return (dst);
}
