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

const char *handle_conversion(va_list ap, const char *p, int *count);
int	handle_string(va_list ap);
int	handle_char(va_list ap);
int	handle_integer(va_list ap, int prec);
int	handle_pointer(va_list ap);
int	handle_integer_hex(va_list ap, bool up_case, int prec);
int	handle_unsigned_integer(va_list ap, int prec);

int	print_hex_str(const char *hex_str, bool with_prefix);

#  ifdef __cplusplus

}
#  endif

# endif
