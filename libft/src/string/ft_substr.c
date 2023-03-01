/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:18:58 by toryoshi          #+#    #+#             */
/*   Updated: 2022/04/23 00:32:15 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	len_sub;

	if (s == NULL)
		return (NULL);
	if (len == 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	len_sub = ft_strlen(s + start);
	if (len < len_sub)
		len_sub = len;
	if (len_sub == SIZE_MAX)
		return (NULL);
	result = malloc(sizeof(char) * (len_sub + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s + start, len_sub + 1);
	return (result);
}
