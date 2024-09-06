/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:31/23 by kfreyer           #+#    #+#             */
/*   Updated: 2024/09/04 14:31:23 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdio.h>

const char	*jump_digits(const char *p)
{
	while (ft_isdigit(*p))
		p++;
	return (p);
}

const char	*extract_int_arg(va_list ap, const char *p, int *nbr)
{
	if (*p == '*')
	{
		*nbr = va_arg(ap, unsigned int);
		return (++p);
	}
	*nbr = ft_atoi(p);
	return (jump_digits(p));
}

int pad(int width, int min_width) {
	while (width < min_width)
	{
		ft_putchar_fd(' ', STDOUT_FILENO);
		width++;
	}
	return width;
}

int	handle_conversion_specifier(va_list ap, char specifier, int min_width, int prec,
		bool padded_left)
{
	char	*str;
	int		width;
	char	c2;

	if (specifier == '%')
	{
		ft_putstr_fd("%%", STDOUT_FILENO);
		return (2);
	}
	if (specifier == 'd' || specifier == 'i')
	{
		str = handle_integer(ap, prec);
		width = ft_strlen(str);
		if (padded_left)
			width = pad(width, min_width);
		ft_putstr_fd(str, STDOUT_FILENO);
		if (!padded_left)
			width = pad(width, min_width);

		free(str);
		return (width);
	}
	if (specifier == 'u')
	{
		str = handle_unsigned_integer(ap, prec);
		width = ft_strlen(str);
		if (padded_left)
			width = pad(width, min_width);
		ft_putstr_fd(str, STDOUT_FILENO);
		if (!padded_left)
			width = pad(width, min_width);
		free(str);
		return (width);
	}
	if (specifier == 'x')
	{
		str = handle_integer_hex(ap, false, prec);
		width = ft_strlen(str);
		if (padded_left)
			width = pad(width, min_width);
		ft_putstr_fd(str, STDOUT_FILENO);
		if (!padded_left)
			width = pad(width, min_width);
		free(str);
		return (width);
	}
	if (specifier == 'X')
	{
		str = handle_integer_hex(ap, true, prec);
		width = ft_strlen(str);
		if (padded_left)
			width = pad(width, min_width);
		ft_putstr_fd(str, STDOUT_FILENO);
		if (!padded_left)
			width = pad(width, min_width);
		free(str);
		return (width);
	}
	if (specifier == 's')
	{
		str = va_arg(ap, char *);
		width = ft_strlen(str);
		if (padded_left)
			width = pad(width, min_width);
		ft_putstr_fd(str, STDOUT_FILENO);
		if (!padded_left)
			width = pad(width, min_width);
		return (width);
	}
	if (specifier == 'p')
	{
		str = handle_pointer(ap);
		width = ft_strlen(str);
		if (padded_left)
			width = pad(width, min_width);
		ft_putstr_fd(str, STDOUT_FILENO);
		if (!padded_left)
			width = pad(width, min_width);
		free(str);
		return (width);
	}
	if (specifier == 'c')
	{
		c2 = (char)va_arg(ap, int);
		width = 1;
		if (padded_left)
			width = pad(width, min_width);
		ft_putchar_fd(c2, STDOUT_FILENO);
		if (!padded_left)
			width = pad(width, min_width);
		return (width);
	}
	return (0);
}

const char	*handle_conversion(va_list ap, const char *p, int *count)
{
	int		min_width;
	int		prec;
	bool	padded_left;

	prec = 1;
	min_width = 0;
	padded_left = true;
	p++;
	if (*p == '-')
	{
		padded_left = false;
		p++;
	}
	p = extract_int_arg(ap, p, &min_width);
	if (min_width < 0)
	{
		padded_left = false;
		min_width = -min_width;
	}
	if (*p == '.')
		p = extract_int_arg(ap, ++p, &prec);
	*count += handle_conversion_specifier(ap, *p, min_width, prec, padded_left);
	p++;
	return (p);
}
