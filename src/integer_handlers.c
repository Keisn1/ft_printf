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


int	handle_integer_hex(va_list ap, bool up_case)
{
	unsigned int	d;

	d = va_arg(ap, unsigned int);
	char hex_str[17];
	ft_unsigned_to_hex(d, hex_str, up_case);
	return print_hex_str(hex_str, false);
}

int	handle_unsigned_integer(va_list ap, int prec)
{
	unsigned int	d;
	int	digits;

	if (prec == 0) {
		return 0;
	}
	d = va_arg(ap, unsigned int);
	digits = 0;
	digits += ft_num_of_digits_unsigned(d);
	while (digits < prec) {
		ft_putchar_fd('0', STDOUT_FILENO);
		digits++;
	}

	ft_put_unsigned_int_fd(d, STDOUT_FILENO);
	return (digits);
}

int	handle_integer(va_list ap, int precision)
{
	int	d;
	int	digits;

	if (precision == 0) {
		return 0;
	}
	d = va_arg(ap, int);
	digits = 0;
	if (d < 0) {
		ft_putchar_fd('-', STDOUT_FILENO);
		digits++;
		precision++;
		d = -d;
	}
	digits += ft_num_of_digits(d);
	while (digits < precision) {
		ft_putchar_fd('0', STDOUT_FILENO);
		digits++;
	}

	ft_putnbr_fd(d, STDOUT_FILENO);
	return (digits);
}

