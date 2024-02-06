/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_list_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:43:11 by mgama             #+#    #+#             */
/*   Updated: 2024/02/06 19:31:08 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_fractal	f_fractal_zc(int type)
{
	t_fractal	fractal;

	fractal.id = 7;
	fractal.mfvar = 1;
	fractal.has_formula = 1;
	fractal.fractal_name = "Mandelbrot Variation 1";
	fractal.fractol_function = &render_zc_set;
	fractal.fractol_function_nothp = &zc_set;
	fractal.has_variants = 0;
	fractal.formula_exp = -1;
	fractal.no_pallet = 0;
	fractal.command_id = 2;
	fractal.home_scale = 50;
	fractal.type_i = type;
	return (fractal);
}

t_fractal	f_fractal_sinzc(int type)
{
	t_fractal	fractal;

	fractal.id = 8;
	fractal.mfvar = 1;
	fractal.has_formula = 1;
	fractal.fractal_name = "Mandelbrot Variation 2";
	fractal.fractol_function = &render_sinzc_set;
	fractal.fractol_function_nothp = &sinzc_set;
	fractal.has_variants = 1;
	fractal.formula_exp = 3;
	fractal.min_exp = 3;
	fractal.no_pallet = 0;
	fractal.command_id = 2;
	fractal.home_scale = 100;
	fractal.type_i = type;
	return (fractal);
}
