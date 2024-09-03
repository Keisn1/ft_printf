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

#include "libftprintf.h"
#include "libft.h"
#include <stdarg.h>
#include <stdbool.h>

int	handle_conversion(va_list ap, char c, bool precision)
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

int	ft_printf(const char *fmt_string, ...)
{
	int			count;
	va_list		ap;
	const char	*p = fmt_string;
	bool precision = false;

	count = 0;
	va_start(ap, fmt_string);
	while (*p != '\0')
	{
		if (*p == '%')
		{
			p++;
			if (*p == '.') {
				precision = true;
				p++;
			}
			count += handle_conversion(ap, *p, precision);
			p++;
			continue ;
		}
		ft_putchar_fd(*(p++), STDOUT_FILENO);
		count++;
	}
	va_end(ap);
	return (count);
}
