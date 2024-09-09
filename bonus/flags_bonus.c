/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:54/35 by kfreyer           #+#    #+#             */
/*   Updated: 2024/09/06 23:54:35 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	init_flags(t_flags *flags)
{
	flags->prec = -1;
	flags->prec_given = false;
	flags->alt_form = false;
	flags->min_width = 0;
	flags->pad_right = true;
	flags->pad_with_zeros = false;
}

const char	*handle_flags(va_list ap, const char *p, t_flags *flags)
{
	init_flags(flags);
	p = check_alt_form(flags, p);
	p = check_zero_padding(flags, p);
	p = check_padded_right(flags, p);
	p = extract_int_arg(ap, p, &(flags->min_width));
	check_field_width(flags);
	if (*p == '.')
	{
		flags->prec_given = true;
		p = extract_int_arg(ap, ++p, &(flags->prec));
	}
	if (is_integer_conversion(*p) && flags->prec != -1)
		flags->pad_with_zeros = false;
	return (p);
}
