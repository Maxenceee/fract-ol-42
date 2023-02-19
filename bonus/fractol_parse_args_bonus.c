/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_parse_args_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:52:14 by mgama             #+#    #+#             */
/*   Updated: 2023/02/19 04:07:57 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	parse_params(int argc, char **argv, t_data *mlx)
{
	int	i;

	i = argc;
	mlx->formula = create_complex_number(0, 0);
	while (i-- > 0)
	{
		if (0 == ft_strcmp(argv[i], "-f") && argc - 1 >= i + 2
			&& ft_isstrdigit(argv[i + 1]) && ft_isstrdigit(argv[i + 2]))
		{
			mlx->formula = create_complex_number(ft_atof(argv[i + 1]),
					ft_atof(argv[i + 2]));
		}
		else if (0 == ft_strcmp(argv[i], "-c") && argc - 1 >= i + 1
			&& ft_isstrdigit(argv[i + 1]))
		{
			mlx->pallet_type = ft_atoi(argv[i + 1]);
			if (mlx->pallet_type > mlx->pallet_nb - 1)
				show_args(0);
		}
		else if (0 == ft_strcmp(argv[i], "-f") || 0 == ft_strcmp(argv[i], "-c"))
			show_args(4);
	}
}

static void	parse_arg_in_mlx(t_data *mlx, int type)
{
	mlx->current_fractal_type = type;
	mlx->fractal_list[type].formula = mlx->formula;
	mlx->fractal_list[type].home_pallet = mlx->pallet_type;
}

static void	parse_args(t_args args, t_data *mlx)
{
	if (ft_strcmp(ft_frstrtolower(args.argv[1]), "julia") == 0
		|| ft_strcmp(ft_frstrtolower(args.argv[1]), "j") == 0)
		parse_arg_in_mlx(mlx, 0);
	else if (ft_strcmp(ft_frstrtolower(args.argv[1]), "mandelbrot") == 0
		|| ft_strcmp(ft_frstrtolower(args.argv[1]), "m") == 0)
		parse_arg_in_mlx(mlx, 1);
	else if (ft_strcmp(ft_frstrtolower(args.argv[1]), "burningship") == 0
		|| ft_strcmp(ft_frstrtolower(args.argv[1]), "b") == 0)
		parse_arg_in_mlx(mlx, 2);
	else if (ft_strcmp(ft_frstrtolower(args.argv[1]), "apollonian") == 0
		|| ft_strcmp(ft_frstrtolower(args.argv[1]), "a") == 0)
		parse_arg_in_mlx(mlx, 3);
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
	if (ft_strcmp(argv[1], "-m") == 0)
	{
		show_commands();
		exit(EXIT_SUCCESS);
	}
	parse_params(argc, argv, mlx);
	parse_args(args, mlx);
}
