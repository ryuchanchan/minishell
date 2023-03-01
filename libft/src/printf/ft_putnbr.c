/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:35:28 by toryoshi          #+#    #+#             */
/*   Updated: 2022/05/15 00:44:26 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(unsigned long unum, char *base, int n, t_bool flag)
{
	unsigned int	len_base;

	len_base = ft_strlen(base);
	if (unum < len_base)
	{
		if (flag)
			ft_putchar_fd(base[unum], 1);
		return (n + 1);
	}
	n = ft_putnbr_base(unum / len_base, base, n + 1, flag);
	unum %= len_base;
	if (flag)
		ft_putchar_fd(base[unum], 1);
	return (n);
}

int	ft_putnbr_hex(unsigned long unum, char *base, int count)
{
	if (ft_is_overlimit(ft_putnbr_base(unum, base, 0, False), count))
		return (-1);
	return (ft_putnbr_base(unum, base, 0, True) + count);
}

int	ft_putptr(void *p, int count)
{
	count = ft_putstr("0x", count);
	if (count == -1)
		return (-1);
	count = ft_putnbr_hex((unsigned long)p, BASE_HEX_L, count);
	return (count);
}

int	ft_putnbr_dec(unsigned int unum, int count)
{
	unsigned long	unum_l;

	unum_l = (unsigned long)unum;
	if (ft_is_overlimit(ft_putnbr_base(unum_l, BASE_DEC, 0, False), count))
		return (-1);
	return (ft_putnbr_base(unum_l, BASE_DEC, 0, True) + count);
}

int	ft_putnbr_signed_dec(int num, int count)
{
	unsigned int	unum;

	unum = num;
	if (num < 0)
	{
		count = ft_putchar('-', count);
		if (count == -1)
			return (-1);
		unum = (unsigned int)(-1 * num);
	}
	count = ft_putnbr_dec(unum, count);
	return (count);
}
