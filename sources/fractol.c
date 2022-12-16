/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:26:13 by mgama             #+#    #+#             */
/*   Updated: 2022/12/16 19:40:10 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	on_fractal_gen(t_data *mlx)
{
	ft_printf("\n\n\033[1;31mGenerating %s...%s\n",
		mlx->fractal_list[mlx->current_fractal_type].fractal_name, "\n\033[0m");
	show_commands(mlx->fractal_list[mlx->current_fractal_type].command_id);	
}

void	switch_fractal(t_data *mlx)
{
	mlx->mouse_lock = 1;
	mlx->scale = INITIAL_SCALE;
	mlx->center_offset = create_complex_number(0, 0);
	
	if (mlx->current_fractal_type + 1 < mlx->fractal_count)
		mlx->current_fractal_type++;
	else
		mlx->current_fractal_type = 0;
	if (mlx->fractal_list[mlx->current_fractal_type].has_formula)
		mlx->formula = mlx->fractal_list[mlx->current_fractal_type].formula;
		
	on_fractal_gen(mlx);
	mlx_update_image(mlx);
}

int	ft_fractol(int argc, char **argv)
{
	t_data	mlx;
	
	init_mlx_f(&mlx);
	init_pallets(&mlx);
	init_fractol(&mlx);

	if (argc > 1)
	{
		fractal_selector(argc, argv, &mlx);
		if (!register_fractals(&mlx))
			exit(EXIT_FAILURE);
		on_fractal_gen(&mlx);
		mlx_update_image(&mlx);
	}
	else
		show_home(&mlx);
	
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
julia

-0.81, -0.27,
0.27, 0.7
*/