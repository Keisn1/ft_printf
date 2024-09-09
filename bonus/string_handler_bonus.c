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

int handle_string(va_list ap, t_flags flags)
{
	char	*s;
	char	*ret;
	int ret_val;

	s = va_arg(ap, char *);
        if (flags.prec == 0 || (flags.prec >= 0 && flags.prec < 6 && !s)) {

		ret_val = 0;
		if (flags.pad_right)
			ret_val = pad(ret_val, flags.min_width, flags.pad_with_zeros);
		if (!flags.pad_right)
			ret_val = pad(ret_val, flags.min_width, flags.pad_with_zeros);
		return ret_val;

        }
	if (!s) {
		ret_val = ft_strlen("(null)");
		if (flags.pad_right)
			ret_val = pad(ret_val, flags.min_width, flags.pad_with_zeros);
		ft_putstr_fd("(null)", STDOUT_FILENO);
		if (!flags.pad_right)
			ret_val = pad(ret_val, flags.min_width, flags.pad_with_zeros);
		return ret_val;
	}

	if (flags.prec < 0) {

		ret_val = ft_strlen(s);
		if (flags.pad_right)
			ret_val = pad(ret_val, flags.min_width, flags.pad_with_zeros);
		ft_putstr_fd(s, STDOUT_FILENO);
		if (!flags.pad_right)
			ret_val = pad(ret_val, flags.min_width, flags.pad_with_zeros);
		return ret_val;
	}
	if ((size_t)flags.prec > ft_strlen(s)) {
		ft_putstr_fd(s, STDOUT_FILENO);
		return ft_strlen(s);
	}

	ret = (char *)malloc(flags.prec + 1);
	if (!ret)
		return 0;

	ft_strlcpy(ret, s, (size_t)flags.prec + 1);

	ret_val = ft_strlen(ret);
	if (flags.pad_right)
		ret_val = pad(ret_val, flags.min_width, flags.pad_with_zeros);
	ft_putstr_fd(ret, STDOUT_FILENO);
	if (!flags.pad_right)
		ret_val = pad(ret_val, flags.min_width, flags.pad_with_zeros);
	free(ret);

	return (ret_val);
}

int handle_char(va_list ap, t_flags flags)
{
	char	c;

	c = (char)va_arg(ap, int);
	return pad_and_print_char(c, flags.min_width, flags.pad_right, flags.pad_with_zeros);
}
