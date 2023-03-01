/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:00:04 by toryoshi          #+#    #+#             */
/*   Updated: 2022/04/20 15:41:10 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	c_c;

	c_c = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c_c)
			return ((char *)(&s[i]));
		i++;
	}
	if (c_c == '\0')
		return ((char *)(&s[i]));
	return (NULL);
}
