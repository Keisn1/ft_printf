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
			p = handle_conversion(ap, p, &count);
			continue ;
		}
		ft_putchar_fd(*(p++), STDOUT_FILENO);
		count++;
	}
	va_end(ap);
	return (count);
}
