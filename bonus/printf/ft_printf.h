/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:33:45 by mgama             #+#    #+#             */
/*   Updated: 2022/12/30 00:54:14 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
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

/* print_width */
void	ft_print_width(int width, int minus, int has_zero, int *count);
void	ft_print_max_width(int width, int max, int has_zero, int *count);

/* print_char */
void	ft_putchar(char c);
void	ft_putchar_c(char c, int *count);
void	ft_print_char(char c, int *count, t_flags flags);

/* print_string */
void	ft_putstrprec(char *str, int prec, int *count);
void	ft_print_str(char *s, int *count, t_flags flags);

/* print_int */
void	ft_print_int(int i, int *count, t_flags flags);

/* print_u_int */
void	ft_print_u_int(unsigned int unsi, int *count, t_flags flags);

/* print_float */
void	ft_print_float(double i, int *count, t_flags flags);

/* print_hex */
void	ft_print_hex(unsigned int ui, int lower,
			int *count, t_flags flags);

/* print_pointer */
void	ft_print_pointer(unsigned long long ull, int *count,
			t_flags flags);

/* strlen */
size_t	ft_strlen(const char *str);

/* isdigit */
int		ft_isdigit(int num);

/* is_valid */
int		ft_is_valid_type(int c);
int		ft_is_valid_flag(int c);

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

/* strcat */
char	*ft_strcat(char *dest, char *src);

/* tolower */
char	*ft_str_tolower(char *str);
int		ft_tolower(int num);

/* convert base */
char	*ft_convert_base(unsigned long long ull, int base);

/* ft_calloc */
void	*ft_calloc(size_t count, size_t size);

/* ft_memset */
void	*ft_memset(void *b, int c, size_t len);

/* ft_bzero */
void	ft_bzero(void *s, size_t n);

/* ft_pow */
double	ft_pow(double x, double y);

#endif /* ft_printf_h */