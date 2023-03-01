/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:20:19 by toryoshi          #+#    #+#             */
/*   Updated: 2022/04/22 18:34:48 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_count(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	create_str(char **s, int size, int n, int is_minus)
{
	int	i;
	int	sign;

	sign = 1;
	if (is_minus)
		sign = -1;
	(*s)[size + is_minus] = '\0';
	i = 0;
	while (i < size)
	{
		(*s)[size - 1 - i + is_minus] = (n % 10 * sign) + '0';
		n /= 10;
		i++;
	}
	if (is_minus)
		(*s)[0] = '-';
	return ;
}

char	*ft_itoa(int n)
{
	int		is_minus;
	int		size;
	char	*str;

	is_minus = 0;
	if (n < 0)
		is_minus = 1;
	size = ft_digit_count(n);
	str = (char *)malloc(sizeof(char) * (size + is_minus + 1));
	if (str == NULL)
		return (NULL);
	create_str(&str, size, n, is_minus);
	return (str);
}
