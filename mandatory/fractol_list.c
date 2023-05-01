/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:17:33 by mgama             #+#    #+#             */
/*   Updated: 2023/05/02 01:52:46 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fractal	f_julia(t_complex_number formula, int type)
{
	t_fractal	fractal;

	fractal.id = 0;
	fractal.has_formula = 1;
	fractal.formula = formula;
	fractal.fractal_name = "Julia set";
	fractal.fractol_function = &julia_set;
	fractal.has_variants = 1;
	fractal.formula_exp = 2;
	fractal.no_pallet = 0;
	fractal.command_id = 1;
	fractal.home_scale = 100;
	fractal.type_i = type;
	return (fractal);
}

t_fractal	f_mandelbrot(int type)
{
	t_fractal	fractal;

	fractal.id = 2;
	fractal.has_formula = 0;
	fractal.fractal_name = "Mandelbrot set";
	fractal.fractol_function = &mandelbrot_set;
	fractal.has_variants = 1;
	fractal.formula_exp = 2;
	fractal.no_pallet = 0;
	fractal.command_id = 2;
	fractal.home_scale = 100;
	fractal.type_i = type;
	return (fractal);
}

t_fractal	f_apollonian(int type)
{
	t_fractal	fractal;

	fractal.id = 4;
	fractal.has_formula = 0;
	fractal.fractal_name = "Apollonian gasket";
	fractal.fractol_function = &apollonian_gasket_set;
	fractal.has_variants = 1;
	fractal.formula_exp = -1;
	fractal.no_pallet = 1;
	fractal.command_id = 3;
	fractal.home_scale = 50;
	fractal.type_i = type;
	return (fractal);
}

t_fractal	f_burningship(int type)
{
	t_fractal	fractal;

	fractal.id = 5;
	fractal.has_formula = 0;
	fractal.fractal_name = "Burningship set";
	fractal.fractol_function = &burningship_set;
	fractal.has_variants = 1;
	fractal.formula_exp = 2;
	fractal.no_pallet = 0;
	fractal.command_id = 2;
	fractal.home_scale = 100;
	fractal.type_i = type;
	return (fractal);
}
