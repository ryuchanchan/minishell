/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:02:42 by toryoshi          #+#    #+#             */
/*   Updated: 2022/07/11 22:13:53 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	ft_should_cutoff(unsigned long num, int n, int sign)
{
	if (sign == -1)
		if (num > ((unsigned long)LONG_MAX + 1 - n) / 10)
			return (1);
	if (sign == 1)
		if (num > ((unsigned long)LONG_MAX - n) / 10)
			return (1);
	return (0);
}

static long	ft_simple_strtol(const char *str, int sign)
{
	size_t			i;
	int				n;
	unsigned long	num;

	num = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		n = str[i] - '0';
		if (sign == -1 && ft_should_cutoff(num, n, sign))
			return (LONG_MIN);
		if (sign == 1 && ft_should_cutoff(num, n, sign))
			return (LONG_MAX);
		num = (num * 10) + n;
		i++;
	}
	return ((long)(sign * num));
}

long	ft_atol(const char *str)
{
	size_t	i;
	int		sign;

	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	return (ft_simple_strtol(&str[i], sign));
}
