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

char	*handle_integer_hex(va_list ap, bool up_case, int prec)
{
	unsigned int	d;

	d = va_arg(ap, unsigned int);
	if (prec == 0 && d == 0)
		return (ft_get_empty_str(1));
	if (prec == 0)
		prec = 1;
	return create_hex_str_from_unsigned(d, up_case, prec);
}

char	*handle_unsigned_integer(va_list ap, int prec)
{
	unsigned int	d;

	d = va_arg(ap, unsigned int);
	if (prec == 0 && d == 0)
		return (ft_get_empty_str(1));
	if (prec == 0)
		prec = 1;
	return (create_int_str_unsigned(d, prec));
}

char	*handle_integer(va_list ap, int prec)
{
	int	d;

	d = va_arg(ap, int);
	if (prec == 0 && d == 0)
		return (ft_get_empty_str(1));
	if (prec <= 0)
		prec = 1;
	return (create_int_str(d, prec));
}
