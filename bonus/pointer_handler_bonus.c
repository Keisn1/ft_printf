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

int	handle_pointer(va_list ap, t_flags flags)
{
	void	*p;
	char	*s;
	int		width;

	p = va_arg(ap, void *);
	if (p == NULL)
		return (pad_and_print_str("(nil)", flags));
	s = create_hex_str_from_pointer(p, false, flags);
	width = pad_and_print_str(s, flags);
	free(s);
	return (width);
}
