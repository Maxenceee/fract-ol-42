/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:13:52 by mgama             #+#    #+#             */
/*   Updated: 2022/12/01 18:55:49 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include "../minilibx_opengl_20191021/mlx.h"
# include "../printf/ft_printf.h"

/* viewport size */
# define WINDOW_WIDTH 1440
# define WINDOW_HEIGHT 740
// # define WINDOW_WIDTH 500
// # define WINDOW_HEIGHT 500
/* viewport defaults scale */
# define INITIAL_SCALE 200
/* julia formula offset */
# define COMPLEX_NUMBER_OFFSET 0.005
/* julia divergence max iterations */
# ifndef MAX_ITER
#  define MAX_ITER 50
# endif
/* apollonian min circle radius */
# define MIN_RADIUS 2
/* mlx */
# define MLX_ERROR 1

typedef struct	s_complex_number
{
	double	x;
	double	y;
}				t_complex_number;

typedef struct	s_color {
	int		pallet_length;
	int		*pallet;
}				t_color;

typedef struct	s_circle {
	double				r;
	double				b;
	t_complex_number	bc;
	t_complex_number	center;
}				t_circle;

typedef struct	s_data {
	void				*img_1;
	void				*img_2;
	void				*curr_img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	void				*window;
	void				*mlx;
	t_complex_number	formula;
	t_complex_number	saved_formula;
	t_complex_number	saved_mouse;
	int					need_save;
	double				scale;
	t_complex_number	center_offset;
	int					key_pressed;
	int					pallet_type;
	int					pallet_nb;
	t_color				*pallets;
	int					no_pallet;
	int					mouse_lock;
	void				(*fractol_function)(struct s_data *);
	char				*fractal_name;
}				t_data;

/* fractol */

void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				switch_mlx_image(t_data *mlx);

void				init_fractol(void (*f)(t_data*), t_data *mlx);
/* MAIN */
int					ft_fractol(char *type, t_complex_number initial_offset);

void				show_args(int nt);
void				show_commands(int t);

/* complex_nums */

void				print_complex(t_complex_number num); // to remove after
double				modulus_complex_2(t_complex_number cpx_num);
t_complex_number	create_complex_number(double x, double y);
double				complex_abs(t_complex_number a);
double				complex_hypot(double x, double y);

/* complex_nums_opperators */

t_complex_number	complex_mul(t_complex_number a, t_complex_number b);
t_complex_number	complex_add(t_complex_number a, t_complex_number b);
t_complex_number	complex_sub(t_complex_number a, t_complex_number b);
t_complex_number	complex_div(t_complex_number a, t_complex_number b);
t_complex_number	complex_sqrt(t_complex_number cmpl);

/* julia */

void				julia_set(t_data *mlx);
int					calule_julia_series(t_complex_number point, t_complex_number point_offset);
t_complex_number	convert_corner_to_center(t_complex_number point, t_complex_number mouse_offset, double scale);
t_complex_number	get_mouse_offset_from_center(t_complex_number point);

/* mandelbrot */

void				mandelbrot_set(t_data *mlx);
int					calule_mandelbrot_series(t_complex_number point);

/* apollonian_gasket */

void				apollonian_gasket_set(t_data *mlx);
void				draw_circle(t_circle circle, t_data *mlx);
void				clear_image(t_data *mlx);
void				draw_gasket(t_circle crls[3], t_data *mlx);
int					ft_min(int a, int b);

/* circles */

t_circle			create_circle(double r, t_complex_number center);
t_circle			*symmetric_set(double x, double y, double radius);
t_circle			*a_symmetric_set(double x, double y, double radius);
t_complex_number	solve_equation(t_complex_number a, t_complex_number b, t_complex_number c);

/* circles_utils */

t_circle			get_adjacent(t_circle c1, t_circle c2, t_circle c3);
t_circle			flip_circle(t_circle c1, t_circle c2, t_circle c3, t_circle c4);
void				recursive_circle(t_circle c1, t_circle c2, t_circle c3, t_circle c4, t_data *mlx);

/* colors */

int					mix(int from, int to, float mix);
int					get_color(float iterations, int *pallet, int colors_nb);
int					color(int r, int g, int b);
void				init_pallets(t_data *mlx);
void				pallet_error(int *colors, t_color *color_data);

/* pallets */

void	pallet_1(t_color *color_data, int idx);
void	pallet_2(t_color *color_data, int idx);
void	pallet_3(t_color *color_data, int idx);
void	pallet_4(t_color *color_data, int idx);
void	pallet_5(t_color *color_data, int idx);
void	pallet_6(t_color *color_data, int idx);
void	pallet_7(t_color *color_data, int idx);

/* mlx_events */

int					stop_mlx(t_data *frame);
int					key_down_event(int key_code, void *param);
int					key_up_event(int key_code, void *param);
int					mouse_event(int button, int x, int y, void *param);
int					mouse_move(int x, int y, void *param);
int					loop_hook_events(void *params);
void				arrow_key_events(int key_code, t_data *mlx);
void				pallet_events(int key_code, t_data *mlx);
void				arrow_letter_events(int key_code, t_data *mlx);
void				key_events(int key_code, t_data *mlx);

/*** utils ***/

char				*ft_strstr(char *str, char *to_find);
int					ft_strcmp(char *s1, char *s2);
int					ft_atoi(const char *str);
double				ft_atof(char *s);
int					ft_isdigit(int num);
int					ft_frtolower(int num);
char				*ft_frstrtolower(char *str);
void				*ft_memcpy(void *dst, const void *src, size_t n);

#endif