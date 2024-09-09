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

int pad_and_print_char(char c, int min_width, bool pad_right,
                       bool pad_with_zeros) {

	int width = 1;
	if (pad_right)
		width += new_pad(width, min_width, pad_with_zeros);
	ft_putchar_fd(c, STDOUT_FILENO);
	if (!pad_right)
		width += new_pad(width, min_width, pad_with_zeros);
	return width;
}

int	new_pad(int width, int min_width, bool zero_padding)
{
	int count = 0;
	while (width < min_width)
	{
		if (zero_padding)
			count += ft_putchar_fd('0', STDOUT_FILENO);
		else
			count += ft_putchar_fd(' ', STDOUT_FILENO);
		width++;
	}
	return (count);
}

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
