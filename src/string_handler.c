/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:43/30 by kfreyer           #+#    #+#             */
/*   Updated: 2024/09/06 19:43:30 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*handle_string(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
		return (ft_strdup("(null)"));
	return (ft_strdup(s));
}

char	*handle_char(va_list ap)
{
	char	c2;
	char	*ret;

	c2 = (char)va_arg(ap, int);
	ret = (char *)malloc(1);
	*ret = c2;
	return (ret);
}
