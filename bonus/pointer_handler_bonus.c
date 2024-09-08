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

#include "ft_printf_bonus.h"
#include "libft.h"

int handle_pointer(va_list ap, t_flags flags)
{
	void	*p;
	int ret_val;

	p = va_arg(ap, void *);
	if (p == NULL) {
		ret_val = ft_strlen("(nil)");
		if (flags.pad_right)
			ret_val = pad(ret_val, flags.min_width, flags.pad_with_zeros);
		ft_putstr_fd("(nil)", STDOUT_FILENO);
		if (!flags.pad_right)
			ret_val = pad(ret_val, flags.min_width, flags.pad_with_zeros);
		return ret_val;
	}
		/* return (ft_strdup("(nil)")); */
	flags.alt_form = true;
	return (create_hex_str_from_unsigned((unsigned long)p, false, flags));
}
