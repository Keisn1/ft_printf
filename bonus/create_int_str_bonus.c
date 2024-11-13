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

char	*get_sign(int d, t_flags flags)
{
	if (d < 0)
		return ("-");
	if (flags.blank && d >= 0)
		return (" ");
	if (flags.with_sign && d >= 0)
		return ("+");
	return ("");
}

char	*create_int_str(int d, t_flags flags)
{
	char	*nbr;
	char	*ret;
	int		size;
	int		nbr_of_digits;
	char	*sign;

	sign = get_sign(d, flags);
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
