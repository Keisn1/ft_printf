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

int	print_char(char *str, t_flags flags)
{
	int	width;

	width = 1;
	if (flags.pad_right)
		width = pad(width, flags.min_width, flags.pad_with_zeros);
	ft_putchar_fd(*str, STDOUT_FILENO);
	if (!flags.pad_right)
		width = pad(width, flags.min_width, flags.pad_with_zeros);
	return (width);
}

int	print_str(char *str, t_flags flags)
{
	int	width;

	width = ft_strlen(str);
	if (flags.pad_right)
		width = pad(width, flags.min_width, flags.pad_with_zeros);
	ft_putstr_fd(str, STDOUT_FILENO);
	if (!flags.pad_right)
		width = pad(width, flags.min_width, flags.pad_with_zeros);
	return (width);
}

const char	*handle_conversion(va_list ap, const char *p, int *count)
{
	t_flags	flags;
	char	specifier;
	char	*str;

	p = handle_flags(ap, p, &flags);
	specifier = *p;
	str = handle_conversion_specifier(ap, specifier, flags.prec);
	if (specifier == 'c')
		*count += print_char(str, flags);
	else
		*count += print_str(str, flags);
	free(str);
	p++;
	return (p);
}
