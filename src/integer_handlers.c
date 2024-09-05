/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:28/49 by kfreyer           #+#    #+#             */
/*   Updated: 2024/09/03 16:28:49 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"


char*	handle_integer_hex(va_list ap, bool up_case, int prec)
{
	unsigned int	d;
	int				digits;
	char			hex_str[17];
	int				nbr_of_zeros;
	int size;

	d = va_arg(ap, unsigned int);
	if (prec == 0 && d == 0)
		return ft_get_empty_str(1);
	if (prec == 0)
		prec = 1;
	digits = ft_unsigned_to_hex(d, hex_str, up_case);
	nbr_of_zeros = 0;
	while (nbr_of_zeros < (prec - digits))
		nbr_of_zeros++;
	size = nbr_of_zeros + digits + 1;
	char* ret = ft_get_empty_str(size);
	add_zeros_to_str(ret, nbr_of_zeros, size);

	ft_strlcat(ret, hex_str+16-digits, size);
	return ret;
}

char*	handle_unsigned_integer(va_list ap, int prec)
{
	unsigned int	d;

	d = va_arg(ap, unsigned int);
	if (prec == 0 && d == 0)
		return (ft_get_empty_str(1));
	if (prec == 0)
		prec = 1;
	return (create_int_str_unsigned(d, prec));
}

char	*handle_integer(va_list ap, int prec)
{
	int	d;

	d = va_arg(ap, int);
	if (prec == 0 && d == 0)
		return (ft_get_empty_str(1));
	if (prec <= 0)
		prec = 1;
	return (create_int_str(d, prec));
}
