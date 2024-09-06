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

int	print_char(char *str, bool padded_left, int min_width, bool zero_padding)
{
	int	width;

	width = 1;
	if (padded_left)
		width = pad(width, min_width, zero_padding);
	ft_putchar_fd(*str, STDOUT_FILENO);
	if (!padded_left)
		width = pad(width, min_width, zero_padding);
	free(str);
	return (width);
}

int	print_str(char *str, bool padded_left, int min_width, bool zero_padding)
{
	int	width;

	width = ft_strlen(str);
	if (padded_left)
		width = pad(width, min_width, zero_padding);
	ft_putstr_fd(str, STDOUT_FILENO);
	if (!padded_left)
		width = pad(width, min_width, zero_padding);
	free(str);
	return (width);
}

const char	*handle_conversion(va_list ap, const char *p, int *count)
{
	int		min_width;
	int		prec;
	bool	padded_left;
	bool	zero_padding;

	prec = 1;
	min_width = 0;
	padded_left = true;
	zero_padding = false;
	p = check_zero_padding(&zero_padding, p);
	p = check_padded_right(&padded_left, &zero_padding, p);
	p = extract_int_arg(ap, p, &min_width);
	check_field_width(&min_width, &padded_left, &zero_padding);
	if (*p == '.')
		p = extract_int_arg(ap, ++p, &prec);
	if (is_integer_conversion(*p) && prec != 1)
		zero_padding = false;
	if (*p == 'c')
		*count += print_char(handle_conversion_specifier(ap, *p, prec),
				padded_left, min_width, zero_padding);
	else
		*count += print_str(handle_conversion_specifier(ap, *p, prec),
				padded_left, min_width, zero_padding);
	p++;
	return (p);
}
