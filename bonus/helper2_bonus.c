/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:52/33 by kfreyer           #+#    #+#             */
/*   Updated: 2024/09/06 19:52:33 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"
#include "libft.h"

int	pad(int width, int min_width, bool zero_padding)
{
	while (width < min_width)
	{
		if (zero_padding)
			ft_putchar_fd('0', STDOUT_FILENO);
		else
			ft_putchar_fd(' ', STDOUT_FILENO);
		width++;
	}
	return (width);
}

bool	is_integer_conversion(char c)
{
	if (c == 'd' || c == 'u' || c == 'x' || c == 'X')
		return (true);
	return (false);
}

const char	*extract_int_arg(va_list ap, const char *p, int *nbr)
{
	if (*p == '*')
	{
		*nbr = va_arg(ap, unsigned int);
		return (++p);
	}
	*nbr = ft_atoi(p);
	return (ft_jump_digits(p));
}
