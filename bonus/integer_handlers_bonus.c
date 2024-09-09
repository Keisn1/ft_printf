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

int	handle_integer_hex(va_list ap, bool up_case, t_flags flags)
{
	unsigned int	d;
	char			*s;
	int				width;

	d = va_arg(ap, unsigned int);
	if (flags.prec == 0 && d == 0)
		return pad_and_print_str("", flags);
	if (flags.alt_form)
		s = create_hex_str_from_unsigned_alt(d, up_case, flags);
	else
		s = create_hex_str_from_unsigned(d, up_case, flags);
	width = pad_and_print_str(s, flags);
	free(s);
	return (width);
}

int	handle_unsigned_integer(va_list ap, t_flags flags)
{
	unsigned int	d;
	char			*s;
	int				width;

	d = va_arg(ap, unsigned int);
	if (flags.prec == 0 && d == 0)
		return pad_and_print_str("", flags);
	s = create_int_str_unsigned(d, flags);
	width = pad_and_print_str(s, flags);
	free(s);
	return (width);
}

int	handle_integer(va_list ap, t_flags flags)
{
	int		d;
	char	*s;
	int		width;

	d = va_arg(ap, int);
	if (flags.prec == 0 && d == 0)
		return pad_and_print_str("", flags);
	if (flags.prec_given)
		flags.pad_with_zeros = false;
	s = create_int_str(d, flags);
	width = pad_and_print_str(s, flags);
	free(s);
	return (width);
}
