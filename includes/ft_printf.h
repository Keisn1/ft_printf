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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>

typedef struct s_flags
{
	bool	pad_with_zeros;
	bool	pad_right;
	int		min_width;
	int		prec;
}			t_flags;

int			ft_printf(const char *fmt_string, ...);

const char	*handle_conversion(va_list ap, const char *p, int *count);
char		*handle_integer(va_list ap, int prec);
char		*handle_unsigned_integer(va_list ap, int prec);
char		*handle_integer_hex(va_list ap, bool up_case, int prec);
char		*handle_pointer(va_list ap, int prec);
char		*create_int_str(int d, int prec);
char		*create_int_str_unsigned(unsigned int d, int prec);
char		*create_hex_str_from_pointer(void *p, int prec);
char		*create_hex_str_from_unsigned(unsigned int d, bool up_case,
				int prec);
char		*handle_string(va_list ap);
char		*handle_char(va_list ap);

int			pad(int width, int min_width, bool zero_padding);
bool		is_integer_conversion(char c);
void		check_field_width(t_flags *flags);
const char	*extract_int_arg(va_list ap, const char *p, int *nbr);
const char	*check_zero_padding(t_flags *flags, const char *p);
const char	*check_padded_right(t_flags *flags, const char *p);

void		init_flags(t_flags *flags);
const char	*handle_flags(va_list ap, const char *p, t_flags *flags);

/* helper */
char		*ft_itoa_unsigned(unsigned int n);
char		*ft_itoa_abs(int d);
void		add_zeros_to_str(char *str, int n, size_t size);

#endif
