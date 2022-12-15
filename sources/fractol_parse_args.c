/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_parse_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:52:14 by mgama             #+#    #+#             */
/*   Updated: 2022/12/15 14:04:29 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractol(void (*f)(t_data*), t_data *mlx)
{
	mlx->fractol_function = *f;
	mlx->scale = INITIAL_SCALE;
	mlx->mouse_offset = 1;
	mlx->key_pressed = 0;
	mlx->mouse_lock = 1;
	mlx->need_save = 0;
	mlx->center_offset = create_complex_number(0, 0);
	switch_mlx_image(mlx);
}

static void	parse_julia(int argc, char **argv)
{
	t_complex_number	offset_f;

	if (ft_strcmp(ft_frstrtolower(argv[1]), "julia") == 0
		|| ft_strcmp(ft_frstrtolower(argv[1]), "j") == 0
		|| ft_strcmp(ft_frstrtolower(argv[1]), "julia3") == 0
		|| ft_strcmp(ft_frstrtolower(argv[1]), "j3") == 0)
	{
		if (argc > 3)
			offset_f = create_complex_number(ft_atof(argv[2]),
					ft_atof(argv[3]));
		else
			show_args(1);
		if (ft_strstr(argv[1], "3"))
			ft_fractol(1, offset_f);
		else
			ft_fractol(0, offset_f);
	}
	else
		show_args(0);
}

void	fractal_selector(int argc, char **argv)
{
	if (ft_strcmp(ft_frstrtolower(argv[1]), "mandelbrot") == 0
		|| ft_strcmp(ft_frstrtolower(argv[1]), "m") == 0)
		ft_fractol(2, create_complex_number(0, 0));
	else if (ft_strcmp(ft_frstrtolower(argv[1]), "apollonian") == 0
		|| ft_strcmp(ft_frstrtolower(argv[1]), "a") == 0)
		ft_fractol(3, create_complex_number(0, 0));
	else if (ft_strcmp(ft_frstrtolower(argv[1]), "burningship") == 0
		|| ft_strcmp(ft_frstrtolower(argv[1]), "b") == 0)
		ft_fractol(4, create_complex_number(0, 0));
	else
		parse_julia(argc, argv);
}
