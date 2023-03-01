/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:28:12 by toryoshi          #+#    #+#             */
/*   Updated: 2022/05/15 00:29:27 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_conversion(char c, va_list *args, size_t *i_p, int count)
{
	if (c == 'c')
		count = ft_putchar((char)va_arg(*args, int), count);
	if (c == 's')
		count = ft_putstr(va_arg(*args, char *), count);
	if (c == 'p')
		count = ft_putptr(va_arg(*args, void *), count);
	if (c == 'd' || c == 'i')
		count = ft_putnbr_signed_dec(va_arg(*args, int), count);
	if (c == 'u')
		count = ft_putnbr_dec(va_arg(*args, unsigned int), count);
	if (c == 'x')
		count = ft_putnbr_hex(va_arg(*args, unsigned int), BASE_HEX_L, count);
	if (c == 'X')
		count = ft_putnbr_hex(va_arg(*args, unsigned int), BASE_HEX_U, count);
	if (c == '%')
		count = ft_putchar('%', count);
	if (c != '\0')
		(*i_p)++;
	(*i_p)++;
	return (count);
}

static int	parse_plain(char c, size_t *i_p, int count)
{
	count = ft_putchar(c, count);
	(*i_p)++;
	return (count);
}

int	ft_parse(const char *str, va_list *args)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			count = parse_conversion(str[i + 1], args, &i, count);
		else
			count = parse_plain(str[i], &i, count);
		if (count == -1)
			return (-1);
	}
	return (count);
}
