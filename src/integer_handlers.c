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
#include <stdio.h>

int	handle_integer_hex(va_list ap, bool up_case, int prec)
{
	unsigned int	d;
	int				digits;
	char			hex_str[17];
	int				nbr_of_zeros;

	d = va_arg(ap, unsigned int);
	if (prec == 0 && d == 0)
		return (0);
	if (prec == 0)
		prec = 1;
	digits = ft_unsigned_to_hex(d, hex_str, up_case);
	nbr_of_zeros = 0;
	while (nbr_of_zeros < (prec - digits))
	{
		ft_putchar_fd('0', STDOUT_FILENO);
		nbr_of_zeros++;
	}
	ft_putstr_fd(hex_str + 16 - digits, STDOUT_FILENO);
	return (digits + nbr_of_zeros);
}

int	handle_unsigned_integer(va_list ap, int prec)
{
	unsigned int	d;
	int				digits;

	d = va_arg(ap, unsigned int);
	if (prec == 0 && d == 0)
		return (0);
	if (prec == 0)
		prec = 1;
	digits = 0;
	digits += ft_num_of_digits_unsigned(d);
	while (digits < prec)
	{
		ft_putchar_fd('0', STDOUT_FILENO);
		digits++;
	}
	ft_put_unsigned_int_fd(d, STDOUT_FILENO);
	return (digits);
}

char	*ft_zero_str(size_t n)
{
	size_t	idx;
	char	*res;

	res = (char *)malloc((n + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[n] = '\0';
	idx = 0;
	while (idx < n)
		((char *)res)[idx++] = '0';
	return (res);
}

char	*handle_integer(va_list ap, int prec)
{
	int		d;
	int		nbr_of_digits;
	int		size;
	char	*sign;
	char	*ret;
	char	*nbr;

	d = va_arg(ap, int);
	if (prec == 0 && d == 0)
		return (ft_get_empty_str());
	if (prec <= 0)
		prec = 1;

	nbr_of_digits = ft_num_of_digits(d);
	if (nbr_of_digits >= prec)
		prec = nbr_of_digits;

	sign = "";
	if (d < 0)
	{
		sign = "-";
		d = -d;
	}

	size = prec + ft_strlen(sign) + 1;
	ret = (char *)malloc(size);
	if (ret == NULL)
		return (NULL);
	*ret = '\0';

	ft_strlcat(ret, sign, size);
	/* printf("\n\nHere: %s\n\n", ret); */
	while (nbr_of_digits < prec)
	{
		ft_strlcat(ret, "0", size);
		nbr_of_digits++;
	}
	nbr = ft_itoa(d);
	ft_strlcat(ret, nbr, size);
	free(nbr);
	return (ret);
}
/* width = 0; */
/* sign = ""; */
/* if (d < 0) */
/* { */
/* 	prec++; */
/* 	sign = "-"; */
/* 	d = -d; */
/* 	width++; */
/* } */
/* width += ft_num_of_digits(d); */
/* if (width >= prec) */
/* 	zeros = ft_get_empty_str(); */
/* else */
/* 	zeros = ft_zero_str(prec - width); */
/* tmp = ft_strjoin(sign, zeros); */
/* free(zeros); */
/* abs_nbr = ft_itoa(d); */
/* ret = ft_strjoin(tmp, abs_nbr); */
/* free(tmp); */
/* free(abs_nbr); */
/* return (ret); */
