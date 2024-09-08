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

/* return value needs to be freeed */
char	*create_int_str(int d, int prec)
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
	if (nbr_of_digits >= prec)
		prec = nbr_of_digits;
	size = prec + ft_strlen(sign) + 1;
	ret = ft_get_empty_str(size);
	ft_strlcat(ret, sign, size);
	add_zeros_to_str(ret, prec - nbr_of_digits, size);
	nbr = ft_itoa_abs(d);
	ft_strlcat(ret, nbr, size);
	free(nbr);
	return (ret);
}

/* return value needs to be freeed */
char	*create_int_str_unsigned(unsigned int d, int prec)
{
	char	*nbr;
	char	*ret;
	int		size;
	int		nbr_of_digits;

	nbr_of_digits = ft_num_of_digits_unsigned(d);
	if (nbr_of_digits >= prec)
		prec = nbr_of_digits;
	size = prec + 1;
	ret = ft_get_empty_str(size);
	add_zeros_to_str(ret, prec - nbr_of_digits, size);
	nbr = ft_itoa_unsigned(d);
	ft_strlcat(ret, nbr, size);
	free(nbr);
	return (ret);
}


char	*create_hex_str_from_unsigned(unsigned long d, bool up_case, int prec, bool alt_form)
{
	char	hex_str[17];
	int		digits;
	int		nbr_of_zeros;
	int		size;
	char	*ret;

	digits = ft_unsigned_long_to_hex(d, hex_str, up_case);
	nbr_of_zeros = 0;
	while (nbr_of_zeros < (prec - digits))
		nbr_of_zeros++;
	size = nbr_of_zeros + digits + 1;
	if (alt_form)
		size += 2;
	ret = ft_get_empty_str(size);
	if (alt_form) 
		ft_strlcat(ret, "0x", size);
	add_zeros_to_str(ret, nbr_of_zeros, size);
	ft_strlcat(ret, hex_str + 16 - digits, size);
	return (ret);
}
