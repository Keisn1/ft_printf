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

const char	*jump_digits(const char *p)
{
	while (ft_isdigit(*p))
		p++;
	return (p);
}

const char	*handle_prec(va_list ap, const char *p, int *prec)
{
	p++;
	if (*p == '*') {
		*prec = va_arg(ap, unsigned int);
		return ++p;
	}
	*prec = ft_atoi(p);
	return jump_digits(p);
}

int	handle_conversion_specifier(va_list ap, char c, int prec)
{
	if (c == '%')
	{
		ft_putstr_fd("%%", STDOUT_FILENO);
		return (2);
	}
	if (c == 'c')
		return (handle_char(ap));
	if (c == 'd' || c == 'i')
		return (handle_integer(ap, prec));
	if (c == 'u')
		return (handle_unsigned_integer(ap));
	if (c == 'x')
		return (handle_integer_hex(ap, false));
	if (c == 'X')
		return (handle_integer_hex(ap, true));
	if (c == 'p')
		return (handle_pointer(ap));
	return (handle_string(ap));
}

const char	*handle_conversion(va_list ap, const char *p, int *count)
{
	int	prec;

	prec = 1;
	p++;
	if (*p == '.')
		p = handle_prec(ap, p, &prec);
	*count += handle_conversion_specifier(ap, *p, prec);
	p++;
	return (p);
}
