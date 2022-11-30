/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:33:45 by mgama             #+#    #+#             */
/*   Updated: 2022/11/29 20:32:39 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_flags
{
	int				already_print;
	int				type;
	int				width;
	int				minus;
	int				plus;
	int				zero;
	int				dot;
	int				star;
	int				hex;
	int				blank;
}					t_flags;

/* printf */
int		ft_printf(const char *fmt, ...);
void	print_type(const char *fmt, va_list *argp, int *count);
void	ft_switch_types(int type, va_list *argp, int *count, t_flags flags);

/* print_width */
void	ft_print_width(int width, int minus, int has_zero, int *count);
void	ft_print_max_width(int width, int max, int has_zero, int *count);

/* print_char */
void	ft_putchar(char c);
void	ft_putchar_c(char c, int *count);
void	ft_print_char(char c, int *count, t_flags flags);

/* print_string */
void	ft_putstrprec(char *str, int prec, int *count);
void	ft_print_spaces(char *str, int *count, t_flags flags);
void	ft_print_str(char *s, int *count, t_flags flags);

/* print_int */
void	ft_print_in_int_spaces(char *d_i, int save_i,
			int *count, t_flags flags);
void	ft_print_int_flags(t_flags *flags, long int *li, int *count);
void	ft_print_int_spaces(char *d_i, int save_i, int *count, t_flags flags);
void	ft_print_int(int i, int *count, t_flags flags);

/* print_u_int */
void	ft_print_in_u_int_spaces(char *unsi_int, int *count, t_flags flags);
void	ft_print_u_int_spaces(char *unsi_int, int *count, t_flags flags);
void	ft_print_u_int(unsigned int unsi, int *count, t_flags flags);

/* print_float */
size_t	ft_strlen_floating_part(const char *str);
void	ft_print_in_float_spaces(char *d_i, double save_f,
			int *count, t_flags flags);
void	ft_print_float_spaces(char *d_i, double save_f,
			int *count, t_flags flags);
void	ft_print_float_flags(t_flags *flags, double *li, int *count);
void	ft_print_float(double i, int *count, t_flags flags);

/* print_hex */
void	ft_print_in_hex_spaces(char *hexa, int lower,
			int *count, t_flags flags);
void	ft_print_hex_spaces(char *hexa, int lower, int *count, t_flags flags);
void	ft_print_hex(unsigned int ui, int lower,
			int *count, t_flags flags);

/* print_pointer */
void	ft_print_in_pointer_spaces(char *pointer, int *count, t_flags flags);
void	ft_print_pointer(unsigned long long ull, int *count,
			t_flags flags);

size_t	ft_strlen(const char *str);
int		ft_isdigit(int num);

/* is_valid */
int		ft_is_valid_type(int c);
int		ft_is_valid_flag(int c);

/* flags */
t_flags	ft_flags(void);
void	ft_check_flags(const char *fmt, va_list *argp,
			t_flags *flags, int *idx);
void	ft_check_flags_identifiers(const char *fmt, va_list *argp,
			t_flags *flags, int *idx);
void	ft_hex_flag(t_flags *flags);
void	ft_blank_flag(t_flags *flags, const char *s, int *idx);
void	ft_minus_flag(t_flags *flags);
void	ft_digit_flag(char c, t_flags *flags);
void	ft_width_flag(va_list *args, t_flags *flags);
void	ft_dot_flag(const char *save, int *start,
			t_flags *flags, va_list *args);
void	ft_plus_flag(t_flags *flags);

/* calloc */
void	*ft_calloc(size_t count, size_t size);

/* itoa */
char	*ft_itoa(long int n);

/* uitoa*/
char	*ft_u_itoa(unsigned int n);

/* ftoa*/
char	*ft_ftoa(double x, int max);

/* strdup */
char	*ft_strdup(const char *src);

/* strjoin */
char	*ft_strjoin(char const *s1, char const *s2);

/* strlcat */
int		ft_strlcat(char *dest, char *src, unsigned int size);

/* tolower */
char	*ft_str_tolower(char *str);
int		ft_tolower(int num);

/* convert base */
char	*ft_put_base(unsigned long long ull_save, int base,
			char *rtn, int count);
char	*ft_convert_base(unsigned long long ull, int base);

#endif