/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:26:13 by mgama             #+#    #+#             */
/*   Updated: 2022/12/14 23:53:49 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	fractal_gen_p(char *type, t_data *mlx)
{
	if (ft_strcmp(type, "apollonian-gasket") == 0)
	{
		mlx->fractal_name = "apollonian-gasket";
		ft_printf("\n\n\033[1;31mGenerating Apollonian gasket fractal...%s\n",
			"\n\033[0m");
		mlx->no_pallet = 1;
		show_commands(3);
		init_fractol(&apollonian_gasket_set, mlx);
	}
	else if (ft_strcmp(type, "burningship") == 0)
	{	
		mlx->fractal_name = "burningship";
		ft_printf("\n\n\033[1;31mGenerating Burningship set...%s\n",
			"\n\033[0m");
		show_commands(2);
		init_fractol(&burningship_set, mlx);
	}
	else
		exit(EXIT_FAILURE);
}

void	fractal_gen(char *type, t_data *mlx)
{
	if (ft_strcmp(type, "julia") == 0)
	{
		mlx->fractal_name = "julia";
		ft_printf("\n\n\033[1;31mGenerating Julia set...%s\n", "\n\033[0m");
		show_commands(1);
		init_fractol(&julia_set, mlx);
	}
	else if (ft_strcmp(type, "julia3") == 0)
	{
		mlx->fractal_name = "julia3";
		ft_printf("\n\n\033[1;31mGenerating Julia 3 set...%s\n", "\n\033[0m");
		show_commands(1);
		init_fractol(&julia3_set, mlx);
	}
	else if (ft_strcmp(type, "mandelbrot") == 0)
	{
		mlx->fractal_name = "mandelbrot";
		ft_printf("\n\n\033[1;31mGenerating Mandelbrot set...%s\n", "\n\033[0m");
		show_commands(2);
		init_fractol(&mandelbrot_set, mlx);
	}
	else
		fractal_gen_p(type, mlx);
}

int	ft_fractol(char *type, t_complex_number initial_offset)
{
	t_data	mlx;

	if (initial_offset.x > 1 || initial_offset.x < -1
		|| initial_offset.y > 1 || initial_offset.y < -1)
		show_args(2);
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "Fract-ol");
	mlx.formula = initial_offset;
	mlx.no_pallet = 0;
	mlx.mouse_lock = 1;
	mlx.need_save = 0;
	mlx.img_1 = mlx_new_image(mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx.img_2 = mlx_new_image(mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_mouse_hook(mlx.window, &mouse_event, &mlx);
	mlx_hook(mlx.window, 17, 1L << 0, &stop_mlx, &mlx);
	mlx_hook(mlx.window, 2, 0L, &key_down_event, &mlx);
	mlx_hook(mlx.window, 3, 0L, &key_up_event, &mlx);
	mlx_hook(mlx.window, 6, 1L << 6, &mouse_move, &mlx);
	fractal_gen(type, &mlx);
	mlx_loop_hook(mlx.mlx, &loop_hook_events, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		fractal_selector(argc, argv);
	else
		show_args(0);
	return (0);
}
