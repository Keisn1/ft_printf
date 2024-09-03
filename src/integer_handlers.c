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