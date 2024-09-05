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

#include "libft.h"
#include "libftprintf.h"

char	*ft_itoa_abs(int d)
{
	if (d == INT_MIN)
		return (ft_strdup("2147483648"));
	if (d < 0)
		return (ft_itoa(-d));
	return (ft_itoa(d));
}

void	add_zeros_to_str(char *str, int n, size_t size)
{
	int	count;

	if (n <= 0)
		return ;
	count = 0;
	while (count < n)
	{
		ft_strlcat(str, "0", size);
		count++;
	}
}

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
