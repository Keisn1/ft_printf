/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:28/49 by kfreyer           #+#    #+#             */
/*   Updated: 2024/09/03 16:28:49 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <unistd.h>

int	handle_unsigned_integer(va_list ap)
{
	unsigned int	d;
	int	digits;

	d = va_arg(ap, unsigned int);
	ft_put_unsigned_int_fd(d, STDOUT_FILENO);
	digits = ft_num_of_digits_unsigned(d);
	return (digits);
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


void	ft_unsigned_to_hex(unsigned int d, char *hex_str)
{
	const char	*hex_chars = "0123456789abcdef";
	int			pos;

	pos = 15;
	while (pos >= 0)
	{
		hex_str[15 - pos] = hex_chars[((long unsigned)d >> (pos * 4)) & 0xF];
		pos--;
	}
	hex_str[16] = '\0'; // Null-terminate the string
}

int	handle_integer_hex(va_list ap)
{
	unsigned int	d;

	d = va_arg(ap, unsigned int);
	char hex_str[17];
	ft_unsigned_to_hex(d, hex_str);
	return print_hex_str(hex_str, false);
}
