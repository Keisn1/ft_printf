/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:46/57 by kfreyer           #+#    #+#             */
/*   Updated: 2024/09/03 15:46:57 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int	handle_string(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	ft_putstr_fd(str, STDOUT_FILENO);
	return (ft_strlen(str));
}

int	handle_char(va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}

int	handle_integer(va_list ap)
{
	int	d;
	int	digits;

	d = va_arg(ap, int);
	ft_putnbr_fd(d, STDOUT_FILENO);
	digits = ft_num_of_digits(d);
	if (d < 0)
		digits++;
	return (digits);
}

int	handle_pointer(va_list ap)
{
	void	*p;
	char	hex_str[17];

	p = va_arg(ap, void *);
	if (p == NULL)
	{
		ft_putstr_fd("(nil)", STDOUT_FILENO);
		return (5);
	}
	ft_ptr_to_hex(p, hex_str);
	return (print_hex_str(hex_str));
}

int	print_hex_str(char *hex_str)
{
	int		count;
	int		idx;
	bool	leading_zero;

	count = 2;
	idx = 0;
	leading_zero = true;
	ft_putstr_fd("0x", STDOUT_FILENO);
	idx = 0;
	while (idx < 16)
	{
		if (hex_str[idx] == '0' && leading_zero)
		{
			idx++;
			continue ;
		}
		leading_zero = false;
		ft_putchar_fd(hex_str[idx++], STDOUT_FILENO);
		count++;
	}
	return (count);
}
