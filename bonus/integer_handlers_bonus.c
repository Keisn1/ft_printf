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
#include "libft.h"

char	*handle_integer_hex(va_list ap, bool up_case, t_flags flags)
{
	unsigned int	d;
	int prec;

	d = va_arg(ap, unsigned int);
	prec = flags.prec;

	if (prec == 0 && d == 0)
		return (ft_get_empty_str(1));
	if (prec == 0)
		prec = 1;
	return (create_hex_str_from_unsigned(d, up_case, prec, flags.alt_form)); /* TODO: change signature */
}

char	*handle_unsigned_integer(va_list ap, t_flags flags)
{
	unsigned int	d;
	int prec;

	d = va_arg(ap, unsigned int);
	prec = flags.prec;
	if (prec == 0 && d == 0)
		return (ft_get_empty_str(1));
	if (prec == 0)
		prec = 1;
	return (create_int_str_unsigned(d, prec));
}

char	*handle_integer(va_list ap, t_flags flags)
{
	int	d;
	int prec;

	d = va_arg(ap, int);
	prec = flags.prec;
	if (prec == 0 && d == 0)
		return (ft_get_empty_str(1));
	if (prec <= 0)
		prec = 1;
	return (create_int_str(d, prec));
}
