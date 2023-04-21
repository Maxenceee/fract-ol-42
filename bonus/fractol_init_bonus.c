/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:44:29 by mgama             #+#    #+#             */
/*   Updated: 2023/04/21 23:22:50 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

static void	init_screen_dims(t_data *mlx)
{
	mlx->screen_dims.left = 0;
	mlx->screen_dims.top = 0;
	mlx->screen_dims.width = WINDOW_WIDTH;
	mlx->screen_dims.height = WINDOW_HEIGHT;
	mlx->screen_dims.center_x = WINDOW_WIDTH * 0.5;
	mlx->screen_dims.center_y = WINDOW_HEIGHT * 0.5;
}

void	init_fractol(t_data *mlx)
{
	mlx->scale = INITIAL_SCALE;
	mlx->mouse_offset = 1;
	mlx->key_pressed = 0;
	mlx->mouse_clicked = 0;
	mlx->mouse_lock = 1;
	mlx->need_save = 0;
	mlx->pallet_type = 0;
	mlx->is_home = 0;
	mlx->prev_variant = 0;
	mlx->next_variant = 0;
	mlx->smooth = 1;
	mlx->no_multithp = 0;
	init_screen_dims(mlx);
	mlx->center_offset = create_complex_number(0, 0);
}

void	init_mlx_f(t_data *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit(1);
	mlx->window = mlx_new_window(mlx->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "Fract-ol");
	if (!mlx->window)
	{
		stop_mlx(mlx);
		return ;
	}
	mlx->img = mlx_new_image(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!mlx->img)
	{
		stop_mlx(mlx);
		return ;
	}
	mlx->transition_req = 0;
	mlx_hook(mlx->window, 17, 1L << 0, &stop_mlx, mlx);
	mlx_hook(mlx->window, 2, 0L, &key_down_event, mlx);
	mlx_hook(mlx->window, 3, 0L, &key_up_event, mlx);
	mlx_hook(mlx->window, 4, 0L, &mouse_down_event, mlx);
	mlx_hook(mlx->window, 5, 0L, &mouse_up_event, mlx);
	mlx_hook(mlx->window, 6, 1L << 6, &mouse_move, mlx);
	mlx_loop_hook(mlx->mlx, &loop_hook_events, mlx);
}

void	init_home_f(t_data *mlx)
{
	int	i;

	i = -1;
	while (++i < mlx->fractal_count)
	{
		if (!mlx->fractal_list[i].no_pallet)
			mlx->fractal_list[i].home_pallet = (int)((float)rand()
					/ (float)RAND_MAX * mlx->pallet_nb);
		if (!mlx->fractal_list[i].has_formula)
			continue ;
		mlx->fractal_list[i].formula.x = ((float)rand()
				/ (float)(RAND_MAX)) * 1;
		if ((float)rand() / (float)(RAND_MAX) > 0.5)
			mlx->fractal_list[i].formula.x = -mlx->fractal_list[i].formula.x;
		mlx->fractal_list[i].formula.y = ((float)rand()
				/ (float)(RAND_MAX)) * 1;
		if ((float)rand() / (float)(RAND_MAX) > 0.5)
			mlx->fractal_list[i].formula.y = -mlx->fractal_list[i].formula.y;
	}
}

int	register_fractals(t_data *mlx)
{
	t_fractal	*fractals;

	mlx->fractal_count = 5;
	fractals = malloc(mlx->fractal_count * sizeof(t_fractal));
	if (!fractals)
		return (0);
	fractals[0] = f_julia(mlx->formula, 0);
	fractals[1] = f_mandelbrot(1);
	fractals[2] = f_burningship(2);
	fractals[3] = f_apollonian(3);
	fractals[4] = f_fractal_tricorn(4);
	mlx->fractal_list = fractals;
	init_home_f(mlx);
	return (1);
}
