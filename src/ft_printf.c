/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:28/16 by kfreyer           #+#    #+#             */
/*   Updated: 2024/08/31 22:28:16 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>
#include <stdbool.h>

int	handle_conversion(va_list ap, char c, int precision)
{
	if (c == '%')
	{
		ft_putstr_fd("%%", STDOUT_FILENO);
		return (2);
	}
	if (c == 'c')
		return (handle_char(ap));
	if (c == 'd' || c == 'i')
		return (handle_integer(ap, precision));
	if (c == 'u')
		return (handle_unsigned_integer(ap));
	if (c == 'x')
		return (handle_integer_hex(ap, false));
	if (c == 'X')
		return (handle_integer_hex(ap, true));
	if (c == 'p')
		return (handle_pointer(ap));
	return (handle_string(ap));
}


int get_precision(const char *p) {
	int prec = 0;
	if (ft_isdigit(*p))
		prec = ft_atoi(p);
	return prec;
}

const char *jump_digits(const char *p) {
	while (ft_isdigit(*p))
		p++;
	return p;
}

int	ft_printf(const char *fmt_string, ...)
{
	int			count;
	va_list		ap;
	int			prec;
	const char	*p = fmt_string;

	prec = 1;
	count = 0;
	va_start(ap, fmt_string);
	while (*p != '\0')
	{
		if (*p == '%')
		{
			p++;
			if (*p == '.')
			{
				p++;
				prec = get_precision(p);
				p = jump_digits(p);
			}
			count += handle_conversion(ap, *p, prec);
			p++;
			continue ;
		}
		ft_putchar_fd(*(p++), STDOUT_FILENO);
		count++;
	}
	va_end(ap);
	return (count);
}
