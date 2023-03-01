/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:       :+:   :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:45:26 by toryoshi          #+#    #+#             */
/*   Updated: 2023/01/07 15:20:52 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	char	*copy;

	if (n == SIZE_MAX)
		return (NULL);
	len = ft_strlen(s1);
	if (n > len)
		n = len;
	copy = (char *)malloc(sizeof(char) * (n + 1));
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, s1, n);
	copy[n] = '\0';
	return (copy);
}
