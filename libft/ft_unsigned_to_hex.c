/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_to_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:36/26 by kfreyer           #+#    #+#             */
/*   Updated: 2024/09/03 17:36:26 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_unsigned_to_hex(unsigned int d, char *hex_str, bool up_case)
{

	const char	*hex_chars = "0123456789abcdef";
	int			pos;

	if (up_case)
		hex_chars = "0123456789ABCDEF";

	pos = 15;
	while (pos >= 0)
	{
		hex_str[15 - pos] = hex_chars[((long unsigned)d >> (pos * 4)) & 0xF];
		pos--;
	}
	hex_str[16] = '\0'; // Null-terminate the string
}
