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

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_flags
{
	bool	hh;
	bool	with_sign;
	bool	blank;
	bool	alt_form;
	bool	pad_with_zeros;
	bool	pad_right;
	int		min_width;
	int		prec;
	bool	prec_given;
}			t_flags;

int ft_printf(const char *fmt_string, ...);

const char	*handle_conversion(va_list ap, const char *p, int *count);

/* handler for specifiers */
int			handle_integer(va_list ap, t_flags flags);
int			handle_unsigned_integer(va_list ap, t_flags flags);
int			handle_integer_hex(va_list ap, bool up_case, t_flags flags);
int			handle_pointer(va_list ap, t_flags flags);
int			handle_string(va_list ap, t_flags flags);
int			handle_char(va_list ap, t_flags flags);

char		*create_int_str(int d, t_flags flags);
char		*create_int_str_unsigned(unsigned int d, t_flags flags);
char		*create_hex_str_from_unsigned(unsigned long d, bool up_case,
				t_flags flags);
char		*create_hex_str_from_unsigned_alt(unsigned long d, bool up_case,
				t_flags flags);
char		*create_hex_str_from_pointer(void *p, bool up_case, t_flags flags);

int			pad_and_print_char(char c, t_flags flags);
int			pad_and_print_str(char *s, t_flags flags);
int			pad(int width, int min_width, bool zero_padding);
bool		is_integer_conversion(char c);
const char	*extract_int_arg(va_list ap, const char *p, int *nbr);

void		init_flags(t_flags *flags);
const char	*handle_flags(va_list ap, const char *p, t_flags *flags);

/* helper */
char		*ft_itoa_unsigned(unsigned int n);
char		*ft_itoa_abs(int d);
void		add_zeros_to_str(char *str, int n, size_t size);

# endif
