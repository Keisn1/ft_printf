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

int	ft_printf(const char *fmt_string, ...)
{
	va_list		ap;
	const char	*p = fmt_string;

	va_start(ap, fmt_string);
	while (*p != '\0')
	{
		if (*p == '%')
		{
			p++;
			switch (*p)
			{
			case 'c':
				/* need a cast here since va_arg only */
				ft_putchar_fd((char)va_arg(ap, int), STDOUT_FILENO);
				break ;
			case 'd':
				/* need a cast here since va_arg only */
				ft_putnbr_fd(va_arg(ap, int), STDOUT_FILENO);
				break ;
			default:
				ft_putstr_fd(va_arg(ap, char *), STDOUT_FILENO);
			}
			p++;
			continue ;
		}
		ft_putchar_fd(*(p++), STDOUT_FILENO);
	}
	va_end(ap);
	return (0);
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
