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

#include "libft.h"
#include "libftprintf.h"

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

int	handle_pointer(va_list ap)
{
	void	*p;
	char	hex_str[17];
	int		digits;

	p = va_arg(ap, void *);
	if (p == NULL)
	{
		ft_putstr_fd("(nil)", STDOUT_FILENO);
		return (5);
	}
	digits = ft_ptr_to_hex(p, hex_str);
	ft_putstr_fd("0x", STDOUT_FILENO);
	ft_putstr_fd(hex_str + 16 - digits, STDOUT_FILENO);
	digits += 2;
	return (digits);
}
