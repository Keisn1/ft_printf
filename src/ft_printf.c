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
#include <unistd.h>

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
			switch (*p) {
			case 'c':
                /* need a cast here since va_arg only */
				ft_putchar_fd((char)va_arg(ap, int), STDOUT_FILENO);
				break;
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
