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

#include "ft_printf_bonus.h"
#include "libft.h"
#include <unistd.h>

int handle_conversion_specifier(va_list ap, char specifier, t_flags flags)
{
	if (specifier == '%')
		return handle_perc();
	if (specifier == 'd' || specifier == 'i')
		return (handle_integer(ap, flags));
	if (specifier == 'u')
		return (handle_unsigned_integer(ap, flags));
	if (specifier == 'x')
		return (handle_integer_hex(ap, false, flags));
	if (specifier == 'X')
		return (handle_integer_hex(ap, true, flags));
	if (specifier == 's')
		return (handle_string(ap, flags));
	if (specifier == 'p')
		return (handle_pointer(ap, flags));
	if (specifier == 'c')
		return (handle_char(ap, flags));
	return 0;
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

	p = handle_flags(ap, p, &flags);
	*count += handle_conversion_specifier(ap, *(p++), flags);
	return (p);
}
