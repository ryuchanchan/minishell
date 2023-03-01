/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:48:20 by toryoshi          #+#    #+#             */
/*   Updated: 2022/04/13 12:19:38 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b_uc;

	b_uc = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		b_uc[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
