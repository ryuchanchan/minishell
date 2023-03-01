/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:50:31 by toryoshi          #+#    #+#             */
/*   Updated: 2022/04/13 12:20:12 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*src_c;
	unsigned char		*dst_c;
	size_t				i;

	src_c = (const unsigned char *)src;
	dst_c = (unsigned char *)dst;
	if (len == 0 || dst_c == src_c)
		return (dst);
	i = 0;
	if (dst_c < src_c)
		return (ft_memcpy(dst, src, len));
	while (i < len)
	{
		dst_c[len - 1 - i] = src_c[len - 1 - i];
		i++;
	}
	return (dst);
}
