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

int	handle_conversion_specifier(va_list ap, char c, int min_width, int prec,
		bool padded_left)
{
	char	*str;
	int		width;

	if (c == '%')
	{
		ft_putstr_fd("%%", STDOUT_FILENO);
		return (2);
	}
	if (c == 'd' || c == 'i')
	{
		str = handle_integer(ap, prec);
		width = ft_strlen(str);
		if (padded_left)
		{
			while (width < min_width)
			{
				ft_putchar_fd(' ', STDOUT_FILENO);
				width++;
			}
		}
		ft_putstr_fd(str, STDOUT_FILENO);
		if (!padded_left)
		{
			while (width < min_width)
			{
				ft_putchar_fd(' ', STDOUT_FILENO);
				width++;
			}
		}
		free(str);
		return (width);
	}
	if (c == 'u')
	{
		str = handle_unsigned_integer(ap, prec);
		width = ft_strlen(str);
		while (width < min_width)
		{
			ft_putchar_fd(' ', STDOUT_FILENO);
			width++;
		}
		ft_putstr_fd(str, STDOUT_FILENO);
		free(str);
		return (width);
	}
	if (c == 'x')
		return (handle_integer_hex(ap, false, prec));
	if (c == 'X')
		return (handle_integer_hex(ap, true, prec));
	if (c == 's')
	{
		str = va_arg(ap, char *);
		width = ft_strlen(str);
		ft_putstr_fd(str, STDOUT_FILENO);
		return (width);
	}
	if (c == 'p')
	{
		str = handle_pointer(ap);
		width = ft_strlen(str);
		ft_putstr_fd(str, STDOUT_FILENO);
		free(str);
		return (width);
	}

	if (c == 'c')
	{
		char c = (char)va_arg(ap, int);
		width = 1;
		ft_putchar_fd(c, STDOUT_FILENO);
		return (width);
	}
	return (0);
}

const char	*handle_conversion(va_list ap, const char *p, int *count)
{
	int		min_width;
	int		prec;
	bool	padded_left;

	padded_left = true;
	prec = 1;
	min_width = 0;
	p++;
	if (*p == '-')
	{
		padded_left = false;
		p++;
	}
	p = extract_int_arg(ap, p, &min_width);
	if (*p == '.')
		p = extract_int_arg(ap, ++p, &prec);
	*count += handle_conversion_specifier(ap, *p, min_width, prec, padded_left);
	p++;
	return (p);
}
