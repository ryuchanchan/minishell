/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:20:28 by toryoshi          #+#    #+#             */
/*   Updated: 2022/04/26 16:29:20 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putabs_fd(int num, int fd)
{
	if (num <= -10)
	{
		ft_putabs_fd(num / 10, fd);
		num %= 10;
	}
	ft_putchar_fd((num * -1) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	else
		n *= -1;
	ft_putabs_fd(n, fd);
}
