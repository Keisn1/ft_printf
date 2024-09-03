/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:30/21 by kfreyer           #+#    #+#             */
/*   Updated: 2024/09/03 15:30:21 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ptr_to_hex(void *p, char *hex_str)
{
	const char	*hex_chars = "0123456789abcdef";
	int			pos;

	pos = 15;
	while (pos >= 0)
	{
		hex_str[15 - pos] = hex_chars[((long unsigned)p >> (pos * 4)) & 0xF];
		pos--;
	}
	hex_str[16] = '\0'; // Null-terminate the string
}
