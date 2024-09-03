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
#include <stdio.h>
#include <unistd.h>

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

int	handle_pointer(va_list ap)
{
	void		*p;
	char		c;
	int			pos;
	int			count;
	const char	*hex_chars = "0123456789abcdef";

	p = va_arg(ap, void *);
	if (p == NULL)
	{
		ft_putstr_fd("(nil)", STDOUT_FILENO);
		return (5);
	}
	pos = 15;
	c = hex_chars[((long unsigned)p >> (pos * 4)) & 0xF];
	while (pos >= 0 && c == '0')
	{
		pos--;
		c = hex_chars[((long unsigned)p >> (pos * 4)) & 0xF];
	}
	count = 2;
	ft_putstr_fd("0x", STDOUT_FILENO);
	while (pos >= 0)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		count++;
		pos--;
		c = hex_chars[((long unsigned)p >> (pos * 4)) & 0xF];
	}
	return (count);
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

/* #include <stdarg.h> */
/* #include <stdio.h> */

/* int ft_printf(const char *fmt_string, ...) { */
/* 	va_list args; */
/* 	va_start(args, fmt_string); */
/* 	return (0); */
/* } */

/* void myFunction(const char* format, ...) { */
/* 	va_list args; */
/* 	va_start(args, format); */

/* 	const char* p = format; */
/* 	while (*p != '\0') { */
/* 		if (*p == 'd') { */
/* 			int i = va_arg(args, int); */
/* 			printf("%d\n", i); */
/* 		} else if (*p == 'c') { */
/* 			char c = va_arg(args, int); // chars are promoted to int */
/* 			printf("%c\n", c); */
/* 		} */
/* 		p++; */
/* 	} */

/* 	va_end(args); */
/* } */

/* int main() { */
/* 	myFunction("dcd", 1, 'a', 3); */
/* 	return (0); */
/* } */
