/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:13:52 by mgama             #+#    #+#             */
/*   Updated: 2022/12/17 01:09:33 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <unistd.h>
# include <time.h>
# include "../minilibx_opengl_20191021/mlx.h"
# include "../printf/ft_printf.h"

/* viewport size */
# define WINDOW_WIDTH 1440
# define WINDOW_HEIGHT 740
/* viewport defaults scale */
# define INITIAL_SCALE 200
/* julia formula offset */
# define COMPLEX_NUMBER_OFFSET 0.005
/* julia divergence max iterations */
# ifndef MAX_ITER
#  define MAX_ITER 100
# endif
/* apollonian min circle radius */
# define MIN_RADIUS 2
/* mlx */
# define MLX_ERROR 1

struct s_complex_number;
struct s_color;
struct s_circle;
struct s_data;
struct s_fractal;
struct s_r_apollonian_c;
struct s_screen_dim;

typedef struct s_complex_number {
	double	x;
	double	y;
}				t_complex_number;

typedef struct s_color {
	int		pallet_length;
	int		*pallet;
}				t_color;

typedef struct s_circle {
	double				r;
	double				b;
	t_complex_number	bc;
	t_complex_number	center;
}				t_circle;

typedef	struct s_screen_dim
{
	int		top;
	int		left;
	int		width;
	int		height;
	int		center_x;
	int		center_y;
}				t_screen_dim;

typedef struct s_data {
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	
	void				*window;
	void				*mlx;
	t_screen_dim		screen_dims;
	int					is_home;
	
	t_complex_number	formula;
	t_complex_number	saved_formula;
	t_complex_number	saved_mouse;
	int					need_save;
	double				scale;
	t_complex_number	center_offset;
	int					key_pressed;
	int					mouse_lock;
	int					mouse_offset;
	
	int					pallet_type;
	int					pallet_nb;
	t_color				*pallets;
	
	struct s_fractal	*fractal_list;
	int					current_fractal_type;
	int					fractal_count;
}				t_data;

typedef struct s_fractal {
	int					id;
	char				*fractal_name;
	int					type_i;
	int					no_pallet;
	int					has_formula;
	t_complex_number	formula;
	void				(*fractol_function)(t_data *, t_screen_dim);
	int					has_variants;
	int					command_id;
	int					variants_count;
}				t_fractal;

typedef struct s_r_apollonian_c {
	t_circle	c1;
	t_circle	c2;
	t_circle	c3;
	t_circle	c4;
}				t_r_apollonian_c;

/* fractol */

int					ft_fractol(int argc, char **argv);
void				on_fractal_gen(t_data *mlx);
void				switch_fractal(t_data *mlx);

/* fractol_init */
void				init_fractol(t_data *mlx);
void				init_mlx_f(t_data *mlx);
int					register_fractals(t_data *mlx);

/* fractol_parse_args */

void				fractal_selector(int argc, char **argv, t_data *mlx);

/* fractol_output */

void				show_commands(int t);
void				show_args(int nt);

/* fractol_home */

int		parse_screen_dims(int width, int height, int parts, t_data *mlx);
void	draw_screen_image(t_screen_dim *screens, int screens_count, t_data *mlx);
int					show_home(t_data *mlx);

/* fractol_list */

t_fractal			f_julia(t_complex_number formula, int type);
t_fractal			f_mandelbrot(int type);
t_fractal			f_apollonian(int type);
t_fractal			f_burningship(int type);
t_fractal			f_julia_3(t_complex_number formula, int type);
t_fractal			f_mandelbrot_3(int type);

/* mlx_draw */

void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				mlx_update_image(t_data *mlx);

/* complex_nums */

double				modulus_complex_2(t_complex_number cpx_num);
t_complex_number	create_complex_number(double x, double y);
double				complex_abs(t_complex_number a);
double				complex_hypot(double x, double y);
t_complex_number	complex_rational_pow(t_complex_number a, unsigned int b);

/* complex_nums_opperators */

t_complex_number	complex_mul(t_complex_number a, t_complex_number b);
t_complex_number	complex_add(t_complex_number a, t_complex_number b);
t_complex_number	complex_sub(t_complex_number a, t_complex_number b);
t_complex_number	complex_div(t_complex_number a, t_complex_number b);
t_complex_number	complex_sqrt(t_complex_number cmpl);

/* julia */

void				julia_set(t_data *mlx, t_screen_dim s_dims);
int					calule_julia_series(t_complex_number point,
						t_complex_number point_offset, double scale);
int					get_max_iter_from_scale(double scale);

t_complex_number	convert_corner_to_center(t_complex_number point,
	t_complex_number mouse_offset, double scale, t_complex_number mids);
t_complex_number	get_mouse_offset_from_center(t_complex_number point);

/* julia3 */

void				julia3_set(t_data *mlx, t_screen_dim s_dims);
int					calule_julia_3_series(t_complex_number point,
						t_complex_number point_offset, double scale);
// int					calule_julia_4_series(t_complex_number point,
// 						t_complex_number point_offset, double scale);

/* mandelbrot */

void				mandelbrot_set(t_data *mlx, t_screen_dim s_dims);
int					calule_mandelbrot_series(t_complex_number point);

/* mandelbrot3 */

void				mandelbrot_3_set(t_data *mlx, t_screen_dim s_dims);
int					calule_mandelbrot_3_series(t_complex_number point);

/* burningship */

void				burningship_set(t_data *mlx, t_screen_dim s_dims);
int					calule_burningship_series(t_complex_number point,
						double scale);

/* apollonian_gasket */

void				apollonian_gasket_set(t_data *mlx, t_screen_dim s_dims);
void				draw_circle(t_circle circle, t_data *mlx, t_screen_dim s_dims);
void				clear_image(t_data *mlx, t_screen_dim s_dims);
void				draw_gasket(t_circle crls[3], t_data *mlx, t_screen_dim s_dims);
int					ft_min(int a, int b);

/* circles */

t_circle			create_circle(double r, t_complex_number center);
t_circle			*symmetric_set(double x, double y, double radius);
t_circle			*a_symmetric_set(double x, double y, double radius);
t_complex_number	solve_equation(t_complex_number a, t_complex_number b,
						t_complex_number c);

/* circles_utils */

t_circle			get_adjacent(t_circle c1, t_circle c2, t_circle c3);
t_circle			flip_circle(t_circle c1, t_circle c2,
						t_circle c3, t_circle c4);
t_r_apollonian_c	create_recursive_circle(t_circle c1, t_circle c2,
						t_circle c3, t_circle c4);
void				recursive_circle(t_r_apollonian_c circles, t_data *mlx,
						t_screen_dim s_dims);

/* colors */

int					mix(int from, int to, float mix);
int					get_color(float iterations, int *pallet, int colors_nb);
int					color(int r, int g, int b);
void				init_pallets(t_data *mlx);
void				pallet_error(int *colors, t_color *color_data);

/* pallets */

void				pallet_1(t_color *color_data, int idx);
void				pallet_2(t_color *color_data, int idx);
void				pallet_3(t_color *color_data, int idx);
void				pallet_4(t_color *color_data, int idx);
void				pallet_5(t_color *color_data, int idx);
void				pallet_6(t_color *color_data, int idx);
void				pallet_7(t_color *color_data, int idx);
void				pallet_8(t_color *color_data, int idx);
void				pallet_9(t_color *color_data, int idx);
void				pallet_10(t_color *color_data, int idx);

/* mlx_events */

int					stop_mlx(t_data *frame);
int					key_down_event(int key_code, void *param);
int					key_up_event(int key_code, void *param);
int					loop_hook_events(void *params);

/* mouse_events */

t_complex_number	aspect_scale(t_data *mlx, t_complex_number mouse_pos,
						t_complex_number mids, double scale);
void				mouse_scroll(int button, t_complex_number temp_pos,
						t_complex_number mids, t_data *mlx);
int					mouse_event(int button, int x, int y, void *param);
int					mouse_move(int x, int y, void *param);

/* key_events */

void				arrow_key_events(int key_code, t_data *mlx);
void				arrow_letter_events(int key_code, t_data *mlx);
void				pallet_events(int key_code, t_data *mlx);
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

#endif /* fractol_h */