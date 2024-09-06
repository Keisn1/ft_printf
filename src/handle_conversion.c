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

int pad(int width, int min_width, bool zero_padding) {
	while (width < min_width)
	{
		if (zero_padding)
			ft_putchar_fd('0', STDOUT_FILENO);
		else
			ft_putchar_fd(' ', STDOUT_FILENO);
		width++;
	}
	return width;
}

/* char*	handle_conversion_specifier(va_list ap, char specifier, int min_width, int prec, bool padded_left) */
char*	handle_conversion_specifier(va_list ap, char specifier,  int prec)
{
	char	c2;

	if (specifier == '%')
		return ft_strdup("%%");
	if (specifier == 'd' || specifier == 'i')
		return handle_integer(ap, prec);
	if (specifier == 'u')
		return  handle_unsigned_integer(ap, prec);
	if (specifier == 'x')
		return handle_integer_hex(ap, false, prec);
	if (specifier == 'X')
		return handle_integer_hex(ap, true, prec);
	if (specifier == 's')
		return ft_strdup(va_arg(ap, char *));
	if (specifier == 'p')
		return  handle_pointer(ap, prec);
	if (specifier == 'c')
	{
		c2 = (char)va_arg(ap, int);
		char* s = ft_strdup(" ");
		s[0] = c2;
		return s;
	}
	return ft_get_empty_str(0);
}

const char	*handle_conversion(va_list ap, const char *p, int *count)
{
	int		min_width;
	int		prec;
	bool	padded_left;
	bool zero_padding;
	int width;

	prec = 1;
	min_width = 0;
	padded_left = true;
	zero_padding = false;
	p++;

	if (*p == '0') {
		zero_padding = true;
		p++;
	}

	if (*p == '-')
	{
		padded_left = false;
		zero_padding = false;
		p++;
	}
	p = extract_int_arg(ap, p, &min_width);
	if (min_width < 0)
	{
		padded_left = false;
		zero_padding = false;
		min_width = -min_width;
	}
	if (*p == '.')
		p = extract_int_arg(ap, ++p, &prec);

	if (*p == 'd' && prec != 1)
		zero_padding = false;
	char* str = handle_conversion_specifier(ap, *p,  prec);
	width = ft_strlen(str);
	if (padded_left)
		width = pad(width, min_width, zero_padding);
	ft_putstr_fd(str, STDOUT_FILENO);
	if (!padded_left)
		width = pad(width, min_width, zero_padding);
	free(str);

	*count += width;
	p++;
	return (p);
}
