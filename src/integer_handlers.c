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

int	handle_integer_hex(va_list ap, bool up_case)
{
	unsigned int	d;

	d = va_arg(ap, unsigned int);
	char hex_str[17];
	ft_unsigned_to_hex(d, hex_str, up_case);
	return print_hex_str(hex_str, false);
}

int	handle_integer(va_list ap, int precision)
{
	int	d;
	int	digits;

	if (precision == 0) {
		return 0;
	}

	digits = 0;
	if (precision == 4) {
		ft_putstr_fd("00", STDOUT_FILENO);
		digits += 2;
	}

	d = va_arg(ap, int);
	ft_putnbr_fd(d, STDOUT_FILENO);
	digits += ft_num_of_digits(d);


	if (d < 0)
		digits++;
	return (digits);
}

