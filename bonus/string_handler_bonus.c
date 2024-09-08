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

#include "ft_printf_bonus.h"
#include "libft.h"

char	*handle_string(va_list ap, t_flags flags)
{
	char	*s;
	char	*ret;

	s = va_arg(ap, char *);
	if (flags.prec == 0)
		return (ft_get_empty_str(1));
	if (!s)
		return (ft_strdup("(null)"));
	if (flags.prec < 0)
		return (ft_strdup(s));
	if ((size_t)flags.prec > ft_strlen(s))
		return (ft_strdup(s));
	ret = (char *)malloc(flags.prec + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s, (size_t)flags.prec + 1);
	return (ret);
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
