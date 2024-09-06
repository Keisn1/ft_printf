/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:47/58 by kfreyer           #+#    #+#             */
/*   Updated: 2024/09/06 19:47:58 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"

char	*ft_itoa_unsigned(unsigned int n)
{
	int		length;
	char	*ret;
	int		idx;

	length = ft_num_of_digits_unsigned(n);
	ret = (char *)malloc(sizeof(char) * (length + 1));
	if (ret == NULL)
		return (NULL);
	idx = 0;
	ret[idx++] = n % 10 + '0';
	n /= 10;
	while (n > 0)
	{
		ret[idx++] = n % 10 + '0';
		n /= 10;
	}
	ret[idx] = '\0';
	ft_rev_char_tab(ret, length);
	return (ret);
}

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
