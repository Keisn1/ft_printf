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

char	*handle_pointer(va_list ap)
{
	void	*p;
	char	hex_str[17];
	int		digits;
	char	*tmp;
	char	*ret;

	p = va_arg(ap, void *);
	if (p == NULL)
		return (ft_strdup("(nil)"));
	digits = ft_ptr_to_hex(p, hex_str);
	tmp = ft_strdup(hex_str + 16 - digits);
	ret = ft_strjoin("0x", tmp);
	free(tmp);
	return (ret);
}
