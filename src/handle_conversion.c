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

#include "ft_printf.h"
#include "libft.h"

char	*handle_conversion_specifier(va_list ap, char specifier, int prec)
{
	if (specifier == '%')
		return (ft_strdup("%"));
	if (specifier == 'd' || specifier == 'i')
		return (handle_integer(ap, prec));
	if (specifier == 'u')
		return (handle_unsigned_integer(ap, prec));
	if (specifier == 'x')
		return (handle_integer_hex(ap, false, prec));
	if (specifier == 'X')
		return (handle_integer_hex(ap, true, prec));
	if (specifier == 's')
		return (handle_string(ap));
	if (specifier == 'p')
		return (handle_pointer(ap, prec));
	if (specifier == 'c')
		return (handle_char(ap));
	return (ft_strdup(""));
}

const char	*handle_conversion(va_list ap, const char *p, int *count)
{
	int		min_width;
	int		prec;
	bool	padded_left;
	bool	zero_padding;
	int		width;
	bool	was_char;
	char	*str;

	prec = 1;
	min_width = 0;
	padded_left = true;
	zero_padding = false;
	if (*p == '0')
	{
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
	if (is_integer_conversion(*p) && prec != 1)
		zero_padding = false;
	was_char = false;
	if (*p == 'c')
		was_char = true;
	str = handle_conversion_specifier(ap, *p, prec);
	if (was_char)
		width = 1;
	else
		width = ft_strlen(str);
	if (padded_left)
		width = pad(width, min_width, zero_padding);
	if (was_char)
		ft_putchar_fd(*str, STDOUT_FILENO);
	else
		ft_putstr_fd(str, STDOUT_FILENO);
	if (!padded_left)
		width = pad(width, min_width, zero_padding);
	free(str);
	*count += width;
	p++;
	return (p);
}
