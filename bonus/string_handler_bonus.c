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
#include <stdio.h>

int	handle_string(va_list ap, t_flags flags)
{
	char	*s;
	char	*ret;
	int		ret_val;

	s = va_arg(ap, char *);
	if (flags.prec == 0 || (flags.prec >= 0 && flags.prec < 6 && !s))
		return (new_pad(0, flags.min_width, flags.pad_with_zeros));
	if (!s)
		return (pad_and_print_str("(null)", flags.min_width, flags.pad_right,
				flags.pad_with_zeros));
	if (flags.prec < 0)
		return (pad_and_print_str(s, flags.min_width, flags.pad_right,
				flags.pad_with_zeros));
	if ((size_t)flags.prec < ft_strlen(s))
	{
		ret = (char *)malloc(flags.prec + 1);
		if (!ret)
			return (0);
		ft_strlcpy(ret, s, (size_t)flags.prec + 1);
		ret_val = pad_and_print_str(ret, flags.min_width, flags.pad_right,
				flags.pad_with_zeros);
		free(ret);
		return (ret_val);
	}
	return (pad_and_print_str(s, flags.min_width, flags.pad_right,
			flags.pad_with_zeros));
}

int	handle_char(va_list ap, t_flags flags)
{
	char	c;

	c = (char)va_arg(ap, int);
	return (pad_and_print_char(c, flags.min_width, flags.pad_right,
			flags.pad_with_zeros));
}
