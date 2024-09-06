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

char	*handle_pointer(va_list ap, int prec)
{
	void	*p;
	char	hex_str[17];
	int		digits;
	int		nbr_of_zeros;
	int		size;
	char	*ret;

	p = va_arg(ap, void *);
	if (p == NULL)
		return (ft_strdup("(nil)"));
	digits = ft_ptr_to_hex(p, hex_str);
	nbr_of_zeros = 0;
	while (nbr_of_zeros < (prec - digits))
		nbr_of_zeros++;
	size = nbr_of_zeros + digits + ft_strlen("0x") + 1;
	ret = ft_get_empty_str(size);
	ft_strlcat(ret, "0x", size);
	add_zeros_to_str(ret, nbr_of_zeros, size);
	ft_strlcat(ret, hex_str + 16 - digits, size);
	return (ret);
}
