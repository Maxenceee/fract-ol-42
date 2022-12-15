/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fractol_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:52:14 by mgama             #+#    #+#             */
/*   Updated: 2022/12/14 23:58:43 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
			ft_fractol("julia3", offset_f);
		else
			ft_fractol("julia", offset_f);
	}
	else
		show_args(0);
}

void	fractal_selector(int argc, char **argv)
{
	if (ft_strcmp(ft_frstrtolower(argv[1]), "mandelbrot") == 0
		|| ft_strcmp(ft_frstrtolower(argv[1]), "m") == 0)
		ft_fractol("mandelbrot", create_complex_number(0, 0));
	else if (ft_strcmp(ft_frstrtolower(argv[1]), "apollonian") == 0
		|| ft_strcmp(ft_frstrtolower(argv[1]), "a") == 0)
		ft_fractol("apollonian-gasket", create_complex_number(0, 0));
	else if (ft_strcmp(ft_frstrtolower(argv[1]), "burningship") == 0
		|| ft_strcmp(ft_frstrtolower(argv[1]), "b") == 0)
		ft_fractol("burningship", create_complex_number(0, 0));
	else
		parse_julia(argc, argv);
}
