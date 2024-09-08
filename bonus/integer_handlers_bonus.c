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

#include "ft_printf_bonus.h"

int handle_integer_hex(va_list ap, bool up_case, t_flags flags)
{
	unsigned int	d;
	int				prec;

	d = va_arg(ap, unsigned int);
	prec = flags.prec;
	if (prec == 0 && d == 0)
		return 0;
	if (prec == 0)
		prec = 1;
	return (create_hex_str_from_unsigned(d, up_case, flags));
}

int	handle_unsigned_integer(va_list ap, t_flags flags)
{
	unsigned int	d;
	int				prec;

	d = va_arg(ap, unsigned int);
	prec = flags.prec;
	if (prec == 0 && d == 0)
		return 0;
	if (prec == 0)
		prec = 1;
	return (create_int_str_unsigned(d, flags));
}

int	handle_integer(va_list ap, t_flags flags)
{
	int	d;

	d = va_arg(ap, int);
	if (flags.prec == 0 && d == 0)
		return 0;
	if (flags.prec <= 0)
		flags.prec = 1;
	return (create_int_str(d, flags));
}
