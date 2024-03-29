/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:26:13 by mgama             #+#    #+#             */
/*   Updated: 2024/02/06 19:37:41 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	on_fractal_gen(t_data *mlx)
{
	ft_printf("\n\n\033[1;31mGenerating %s...%s\n",
		mlx->fractal_list[mlx->curr_fractal_type].fractal_name, "\n\033[0m");
	show_commands();
}

void	switch_fractal(t_data *mlx)
{
	mlx->mouse_lock = 1;
	mlx->scale = INITIAL_SCALE;
	mlx->center_offset = create_complex_number(0, 0);
	if (mlx->curr_fractal_type + 1 < mlx->fractal_count)
		mlx->curr_fractal_type++;
	else
		mlx->curr_fractal_type = 0;
	if (mlx->fractal_list[mlx->curr_fractal_type].has_formula)
		mlx->formula = mlx->fractal_list[mlx->curr_fractal_type].formula;
	mlx->fractal_list[mlx->curr_fractal_type].home_pallet = mlx->pallet_type;
	mlx_update_image_multitp(mlx);
}

int	ft_fractol(int argc, char **argv)
{
	t_data	mlx;

	ft_bzero(&mlx, sizeof(t_data));
	init_fractol(&mlx);
	init_mlx_f(&mlx);
	init_pallets(&mlx);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel,
			&mlx.line_length, &mlx.endian);
	if (argc > 1)
	{
		if (!register_fractals(&mlx))
			exit(EXIT_FAILURE);
		fractal_selector(argc, argv, &mlx);
		on_fractal_gen(&mlx);
		mlx_update_image_multitp(&mlx);
	}
	else
	{
		if (!register_fractals(&mlx))
			exit(EXIT_FAILURE);
		show_commands();
		show_home(&mlx);
	}
	mlx_loop(mlx.mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	srand(time(NULL));
	if (ft_fractol(argc, argv))
		return (1);
	return (0);
}

/*
julia fav
-0.81 -0.27i
0.27 0.7i
0.4 0i
-0.752 0.429i
0.064 +0.725i 
0.374 0.441i
-0.888 0.277i
-1.25 0i
0.477 -0.145i 

julia3 fav
-0.782 0.138i
-0.727 0.213i

julia4 fav
-0.313 -0.533i

julia5 fav
-0.39 -0.725i

julia7 fav
0.69 0.54i

Mandelbrot vr2
Z^3 +0.597 -0.000i 
Z^3 +0.540 +0.092i
Z^3 +0.597 +0.000i
Z^3 +0.529 +0.001i
Z^3 +0.572 -0.065i
*/