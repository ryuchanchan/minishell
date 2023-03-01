/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:30:14 by toryoshi          #+#    #+#             */
/*   Updated: 2022/05/15 00:48:30 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *vla, ...)
{
	va_list	args;
	int		count;

	va_start(args, vla);
	count = ft_parse(vla, &args);
	va_end(args);
	return (count);
}
