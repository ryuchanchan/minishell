/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:19:29 by toryoshi          #+#    #+#             */
/*   Updated: 2022/04/29 19:14:31 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{	
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}

static size_t	get_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	if (len_s1 == 0)
		return (0);
	i = len_s1 - 1;
	while (i != 0)
	{	
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	size;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (end == 0)
		return (ft_strdup(""));
	size = end - start + 1;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, &s1[start], size + 1);
	return (result);
}
