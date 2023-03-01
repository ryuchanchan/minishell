/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:00:26 by toryoshi          #+#    #+#             */
/*   Updated: 2022/04/20 15:39:58 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*s_result;
	char	c_c;

	s_result = NULL;
	c_c = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c_c)
			s_result = (char *)(&s[i]);
		i++;
	}
	if (c_c == '\0')
		return ((char *)(&s[i]));
	return (s_result);
}
