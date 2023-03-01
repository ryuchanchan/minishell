/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:38:34 by toryoshi          #+#    #+#             */
/*   Updated: 2022/05/15 00:45:39 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int count)
{
	if (ft_is_overlimit(1, count))
		return (-1);
	ft_putchar_fd(c, 1);
	return (1 + count);
}

int	ft_putstr(char *str, int count)
{
	size_t	len;

	if (str == NULL)
		return (ft_putstr("(null)", count));
	len = ft_strlen(str);
	if (len >= (size_t)INT_MAX || ft_is_overlimit(len, count))
		return (-1);
	ft_putstrn_fd(str, len, 1);
	return (len + count);
}
