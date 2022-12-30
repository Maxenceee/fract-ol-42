/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_parse_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:52:14 by mgama             #+#    #+#             */
/*   Updated: 2022/12/29 23:52:36 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	parse_arg_in_mlx(t_data *mlx, int type, t_complex_number start_off)
{
	if (start_off.x > 1 || start_off.x < -1
		|| start_off.y > 1 || start_off.y < -1)
		show_args(2);
	mlx->current_fractal_type = type;
	mlx->formula = start_off;
	mlx->fractal_list[type].formula = start_off;
	mlx->fractal_list[type].home_pallet = mlx->pallet_type;
}

static void	parse_julia(int argc, char **argv, t_data *mlx)
{
	t_complex_number	offset_f;

	if (ft_strcmp(ft_frstrtolower(argv[1]), "julia") == 0
		|| ft_strcmp(ft_frstrtolower(argv[1]), "j") == 0)
	{
		if (argc < 4)
			show_args(1);
		if (argc > 4)
			show_args(0);
		offset_f = create_complex_number(ft_atof(argv[2]),
				ft_atof(argv[3]));
		parse_arg_in_mlx(mlx, 0, offset_f);
	}
	else
		show_args(0);
}

void	fractal_selector(int argc, char **argv, t_data *mlx)
{
	if (ft_strcmp(ft_frstrtolower(argv[1]), "mandelbrot") == 0
		|| ft_strcmp(ft_frstrtolower(argv[1]), "m") == 0)
		parse_arg_in_mlx(mlx, 1, create_complex_number(0, 0));
	else if (ft_strcmp(ft_frstrtolower(argv[1]), "burningship") == 0
		|| ft_strcmp(ft_frstrtolower(argv[1]), "b") == 0)
		parse_arg_in_mlx(mlx, 2, create_complex_number(0, 0));
	else if (ft_strcmp(ft_frstrtolower(argv[1]), "apollonian") == 0
		|| ft_strcmp(ft_frstrtolower(argv[1]), "a") == 0)
		parse_arg_in_mlx(mlx, 3, create_complex_number(0, 0));
	else
		parse_julia(argc, argv, mlx);
}
