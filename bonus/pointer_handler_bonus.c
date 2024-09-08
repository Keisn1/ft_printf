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

char	*handle_pointer(va_list ap, t_flags flags)
{
	void	*p;

	p = va_arg(ap, void *);
	if (p == NULL)
		return (ft_strdup("(nil)"));
	flags.alt_form = true;
	return create_hex_str_from_unsigned((unsigned long)p, false, flags.prec, flags.alt_form);
}
