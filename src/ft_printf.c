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

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <stdbool.h>

int	handle_string(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	ft_putstr_fd(str, STDOUT_FILENO);
	return (ft_strlen(str));
}

int	handle_char(va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}

int	handle_integer(va_list ap)
{
	int	d;
	int	digits;

	d = va_arg(ap, int);
	ft_putnbr_fd(d, STDOUT_FILENO);
	digits = ft_num_of_digits(d);
	if (d < 0)
		digits++;
	return (digits);
}

int	print_hex_str(char *hex_str)
{
	int		count;
	int		idx;
	bool	leading_zero;

	count = 2;
	idx = 0;
	leading_zero = true;
	ft_putstr_fd("0x", STDOUT_FILENO);
	idx = 0;
	while (idx < 16)
	{
		if (hex_str[idx] == '0' && leading_zero)
		{
			idx++;
			continue ;
		}
		leading_zero = false;
		ft_putchar_fd(hex_str[idx++], STDOUT_FILENO);
		count++;
	}
	return (count);
}

int	handle_pointer(va_list ap)
{
	void	*p;
	char	hex_str[17];

	p = va_arg(ap, void *);
	if (p == NULL)
	{
		ft_putstr_fd("(nil)", STDOUT_FILENO);
		return (5);
	}
	ft_ptr_to_hex(p, hex_str);
	return (print_hex_str(hex_str));
}

int	handle_conversion(va_list ap, char c)
{
	if (c == '%')
	{
		ft_putstr_fd("%%", STDOUT_FILENO);
		return (2);
	}
	if (c == 'c')
		return (handle_char(ap));
	if (c == 'd')
		return (handle_integer(ap));
	if (c == 'p')
		return (handle_pointer(ap));
	return (handle_string(ap));
}

int	ft_printf(const char *fmt_string, ...)
{
	int			count;
	va_list		ap;
	const char	*p = fmt_string;

	count = 0;
	va_start(ap, fmt_string);
	while (*p != '\0')
	{
		if (*p == '%')
		{
			p++;
			count += handle_conversion(ap, *p);
			p++;
			continue ;
		}
		ft_putchar_fd(*(p++), STDOUT_FILENO);
		count++;
	}
	va_end(ap);
	return (count);
}
