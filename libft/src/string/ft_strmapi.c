/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:15:53 by toryoshi          #+#    #+#             */
/*   Updated: 2022/04/26 17:04:11 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ss;

	if (s == NULL)
		return (NULL);
	ss = ft_strdup(s);
	if (ss == NULL)
		return (NULL);
	if (f == NULL)
		return (ss);
	i = 0;
	while (ss[i] != '\0')
	{
		ss[i] = f(i, ss[i]);
		i++;
	}
	return (ss);
}
