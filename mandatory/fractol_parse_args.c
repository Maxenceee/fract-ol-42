/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_parse_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:52:14 by mgama             #+#    #+#             */
/*   Updated: 2023/01/19 22:41:58 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	parse_arg_in_mlx(t_data *mlx, int type, t_complex_number start_off)
{
	if (start_off.x > 1 || start_off.x < -1
		|| start_off.y > 1 || start_off.y < -1)
		show_args(2);
	mlx->current_fractal_type = type;
	mlx->formula = start_off;
	mlx->fractal_list[type].formula = start_off;
	mlx->fractal_list[type].home_pallet = mlx->pallet_type;
}

static void	parse_julia(t_args args, t_data *mlx)
{
	t_complex_number	offset_f;
	int					pallet;

	if (args.argc < 4)
		show_args(1);
	if (args.argc > 4)
	{
		pallet = ft_atoi(args.argv[4]);
		if (pallet > mlx->pallet_nb - 1)
			show_args(0);
		mlx->pallet_type = pallet;
	}
	offset_f = create_complex_number(ft_atof(args.argv[2]),
			ft_atof(args.argv[3]));
	parse_arg_in_mlx(mlx, 0, offset_f);
}

static void	parse_args(t_args args, t_data *mlx)
{
	int	pallet;

	if (args.argc > 2)
	{
		pallet = ft_atoi(args.argv[2]);
		if (pallet > mlx->pallet_nb - 1)
			show_args(0);
		mlx->pallet_type = pallet;
	}
	if (ft_strcmp(ft_frstrtolower(args.argv[1]), "mandelbrot") == 0
		|| ft_strcmp(ft_frstrtolower(args.argv[1]), "m") == 0)
		parse_arg_in_mlx(mlx, 1, create_complex_number(0, 0));
	else if (ft_strcmp(ft_frstrtolower(args.argv[1]), "burningship") == 0
		|| ft_strcmp(ft_frstrtolower(args.argv[1]), "b") == 0)
		parse_arg_in_mlx(mlx, 2, create_complex_number(0, 0));
	else if (ft_strcmp(ft_frstrtolower(args.argv[1]), "apollonian") == 0
		|| ft_strcmp(ft_frstrtolower(args.argv[1]), "a") == 0)
		parse_arg_in_mlx(mlx, 3, create_complex_number(0, 0));
	else
		show_args(0);
}

void	fractal_selector(int argc, char **argv, t_data *mlx)
{
	t_args	args;

	args.argc = argc;
	args.argv = argv;
	if (ft_strcmp(argv[1], "-h") == 0)
		show_args(4);
	if (ft_strcmp(ft_frstrtolower(args.argv[1]), "julia") == 0
		|| ft_strcmp(ft_frstrtolower(args.argv[1]), "j") == 0)
		parse_julia(args, mlx);
	else
		parse_args(args, mlx);
}
