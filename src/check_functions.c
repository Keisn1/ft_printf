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

const char	*check_zero_padding(bool *zero_padding, const char *p)
{
	if (*p == '0')
	{
		*zero_padding = true;
		p++;
	}
	return (p);
}

const char	*check_padded_right(bool *padded_left, bool *zero_padding,
		const char *p)
{
	if (*p == '-')
	{
		*padded_left = false;
		*zero_padding = false;
		p++;
	}
	return (p);
}

void	check_field_width(int *min_width, bool *padded_left, bool *zero_padding)
{
	if (*min_width < 0)
	{
		*padded_left = false;
		*zero_padding = false;
		*min_width = -(*min_width);
	}
}
