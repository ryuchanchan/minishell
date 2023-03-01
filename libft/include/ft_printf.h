/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toryoshi </var/mail/toryoshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:31:24 by toryoshi          #+#    #+#             */
/*   Updated: 2022/05/15 00:34:36 by toryoshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define BASE_DEC "0123456789"
# define BASE_HEX_U "0123456789ABCDEF"
# define BASE_HEX_L "0123456789abcdef"

typedef enum e_bool
{
	False,
	True
}	t_bool;

int		ft_is_overlimit(int n, int count);
void	ft_putstrn_fd(char *s, size_t len, int fd);

int		ft_putchar(char c, int count);
int		ft_putstr(char *str, int count);
int		ft_putnbr_dec(unsigned int unum, int count);
int		ft_putnbr_signed_dec(int num, int count);
int		ft_putnbr_hex(unsigned long unum, char *base, int count);
int		ft_putptr(void *p, int count);

int		ft_parse(const char *str, va_list *args);

#endif
