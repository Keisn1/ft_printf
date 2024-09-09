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
	flags->blank = false;
	flags->with_sign = false;
}

bool	is_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
		return (true);
	return (false);
}

const char	*extract_flags(const char *p, t_flags *flags)
{
	while (is_flag(*p))
	{
		if (*p == '+')
			flags->with_sign = true;
		if (*p == '#')
			flags->alt_form = true;
		if (*p == '0')
			flags->pad_with_zeros = true;
		if (*p == ' ')
			flags->blank = true;
		if (*p == '-')
		{
			flags->pad_with_zeros = false;
			flags->pad_right = false;
		}
		p++;
	}
	return (p);
}

void	check_field_width(t_flags *flags)
{
	if (flags->min_width < 0)
	{
		flags->pad_right = false;
		flags->pad_with_zeros = false;
		flags->min_width = -(flags->min_width);
	}
}

const char	*handle_flags(va_list ap, const char *p, t_flags *flags)
{
	init_flags(flags);
	p = extract_flags(p, flags);
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
