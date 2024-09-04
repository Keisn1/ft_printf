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

#include "libft.h"
#include "libftprintf.h"
#include <unistd.h>

int	handle_integer_hex(va_list ap, bool up_case)
{
	unsigned int	d;
	int				digits;
	char			hex_str[17];

	d = va_arg(ap, unsigned int);
	digits = ft_unsigned_to_hex(d, hex_str, up_case);
	print_hex_str(hex_str, false);
	return (digits);
}

int	handle_unsigned_integer(va_list ap, int prec)
{
	unsigned int	d;
	int				digits;

	d = va_arg(ap, unsigned int);
	if (prec == 0 && d == 0)
	{
		if (d == 0)
			return (0);
		prec = 1;
	}
	digits = 0;
	digits += ft_num_of_digits_unsigned(d);
	while (digits < prec)
	{
		ft_putchar_fd('0', STDOUT_FILENO);
		digits++;
	}
	ft_put_unsigned_int_fd(d, STDOUT_FILENO);
	return (digits);
}

int	handle_integer(va_list ap, int prec)
{
	int	d;
	int	digits;

	d = va_arg(ap, int);
	if (prec == 0 && d == 0)
	{
		if (d == 0)
			return (0);
		prec = 1;
	}
	digits = 0;
	if (d < 0)
	{
		ft_putchar_fd('-', STDOUT_FILENO);
		digits++;
		prec++;
		d = -d;
	}
	digits += ft_num_of_digits(d);
	while (digits < prec)
	{
		ft_putchar_fd('0', STDOUT_FILENO);
		digits++;
	}
	ft_putnbr_fd(d, STDOUT_FILENO);
	return (digits);
}
