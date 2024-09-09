/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 23:04/55 by kfreyer           #+#    #+#             */
/*   Updated: 2024/09/05 23:04:55 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

char	*create_int_str(int d, t_flags flags)
{
	char	*nbr;
	char	*ret;
	int		size;
	int		nbr_of_digits;
	char	*sign;

	sign = "";
	if (d < 0)
		sign = "-";
	nbr_of_digits = ft_num_of_digits(d);
	if (nbr_of_digits >= flags.prec)
		flags.prec = nbr_of_digits;
	size = flags.prec + ft_strlen(sign) + 1;
	if (flags.pad_with_zeros && (flags.min_width >= size))
		size = flags.min_width + 1;
	ret = ft_get_empty_str(size);
	ft_strlcat(ret, sign, size);
	if (flags.pad_with_zeros)
		add_zeros_to_str(ret, flags.min_width - (flags.prec + ft_strlen(sign)),
			size);
	add_zeros_to_str(ret, flags.prec - nbr_of_digits, size);
	nbr = ft_itoa_abs(d);
	ft_strlcat(ret, nbr, size);
	free(nbr);
	return (ret);
}

char	*create_int_str_unsigned(unsigned int d, t_flags flags)
{
	char	*nbr;
	char	*ret;
	int		size;
	int		nbr_of_digits;

	nbr_of_digits = ft_num_of_digits_unsigned(d);
	if (nbr_of_digits >= flags.prec)
		flags.prec = nbr_of_digits;
	size = flags.prec + 1;
	ret = ft_get_empty_str(size);
	add_zeros_to_str(ret, flags.prec - nbr_of_digits, size);
	nbr = ft_itoa_unsigned(d);
	ft_strlcat(ret, nbr, size);
	free(nbr);
	return (ret);
}

char	*create_hex_str_from_unsigned(unsigned long d, bool up_case,
		t_flags flags)
{
	char	hex_str[17];
	int		digits;
	int		nbr_of_zeros;
	int		size;
	char	*ret;

	digits = ft_unsigned_long_to_hex(d, hex_str, up_case);
	nbr_of_zeros = 0;
	while (nbr_of_zeros < (flags.prec - digits))
		nbr_of_zeros++;
	size = nbr_of_zeros + digits + 1;
	if (flags.alt_form)
		size += 2;
	ret = ft_get_empty_str(size);
	if (flags.alt_form && d != 0)
	{
		if (up_case)
			ft_strlcat(ret, "0X", size);
		else
			ft_strlcat(ret, "0x", size);
	}
	add_zeros_to_str(ret, nbr_of_zeros, size);
	ft_strlcat(ret, hex_str + 16 - digits, size);
	return (ret);
}
