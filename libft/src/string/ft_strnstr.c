/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:02:37 by toryoshi          #+#    #+#             */
/*   Updated: 2022/04/15 02:02:41 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_needle;

	len_needle = ft_strlen(needle);
	if (len_needle == 0)
		return ((char *)haystack);
	if (len < len_needle)
		return (NULL);
	i = 0;
	while (i < len - len_needle + 1 && haystack[i] != '\0')
	{
		if (ft_strncmp(&haystack[i], needle, len_needle) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
