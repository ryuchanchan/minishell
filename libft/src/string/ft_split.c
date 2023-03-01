/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:19:58 by toryoshi          #+#    #+#             */
/*   Updated: 2022/04/22 18:25:47 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_arr(char const *s, const char c)
{
	size_t	i;
	size_t	count;
	int		is_prev_delimiter;

	is_prev_delimiter = 1;
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (is_prev_delimiter && s[i] != c)
			count++;
		is_prev_delimiter = (s[i] == c);
		i++;
	}
	return (count);
}

static size_t	ft_count_word(char *s, const char c)
{
	size_t	i;

	i = 0;
	while (!(s[i] == c || s[i] == '\0'))
		i++;
	return (i);
}

static char	*ft_create_elm(char **s, const char c)
{
	size_t	i;
	size_t	len_word;
	char	*result;

	i = 0;
	while ((*s)[i] == c)
		i++;
	*s = &(*s)[i];
	len_word = ft_count_word(*s, c);
	result = (char *)malloc(sizeof(char) * (len_word + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, *s, len_word + 1);
	*s = &(*s)[len_word];
	return (result);
}

static char	**ft_free_arr(char **splitted, size_t len_arr)
{
	size_t	i;

	i = 0;
	while (i < len_arr)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	*s_mutable;
	char	**splitted;
	size_t	len_arr;
	size_t	i;

	if (!s)
		return (NULL);
	len_arr = ft_count_arr(s, c);
	splitted = (char **)malloc(sizeof(char *) * (len_arr + 1));
	if (splitted == NULL)
		return (NULL);
	s_mutable = (char *)s;
	i = 0;
	while (i < len_arr)
	{
		splitted[i] = ft_create_elm(&s_mutable, c);
		if (splitted[i] == NULL)
			return (ft_free_arr(splitted, i));
		i++;
	}
	splitted[len_arr] = NULL;
	return (splitted);
}
