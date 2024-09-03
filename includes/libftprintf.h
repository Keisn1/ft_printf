/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:28/10 by kfreyer           #+#    #+#             */
/*   Updated: 2024/08/31 22:28:10 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include <stdbool.h>

# ifdef __cplusplus

extern "C"
{
#endif
int ft_printf(const char *fmt_string, ...);
int	handle_string(va_list ap);
int	handle_char(va_list ap);
int	handle_integer(va_list ap);
int	handle_pointer(va_list ap);
int	print_hex_str(char *hex_str);
int	handle_unsigned_integer(va_list ap);
#  ifdef __cplusplus

}
#  endif

# endif