/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:18/47 by kfreyer           #+#    #+#             */
/*   Updated: 2024/09/06 21:18:47 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*check_zero_padding(t_flags *flags, const char *p)
{
	if (*p == '0')
	{
		flags->pad_with_zeros= true;
		p++;
	}
	return (p);
}

const char	*check_padded_right(t_flags *flags, const char *p)
{
	if (*p == '-')
	{
		flags->pad_right = false;
		flags->pad_with_zeros = false;
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
