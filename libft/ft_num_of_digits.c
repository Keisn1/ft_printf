/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_of_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:00/21 by kfreyer           #+#    #+#             */
/*   Updated: 2024/09/03 13:00:21 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_of_digits(int d)
{
	int	count;

	count = 1;
	if (d < -10) {
		d /= -10;
		count++;
	}
	while (d > 10)
	{
		d /= 10;
		count++;
	}
	return (count);
}
