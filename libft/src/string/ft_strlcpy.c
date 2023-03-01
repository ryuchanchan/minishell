/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:50:53 by toryoshi          #+#    #+#             */
/*   Updated: 2022/04/10 14:42:40 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	if (len_src + 1 < dstsize)
	{
		ft_memcpy(dst, src, len_src + 1);
		return (len_src);
	}
	ft_memcpy(dst, src, dstsize - 1);
	dst[dstsize - 1] = '\0';
	return (len_src);
}
