/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:17:33 by mgama             #+#    #+#             */
/*   Updated: 2022/12/17 21:22:02 by mgama            ###   ########.fr       */
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
	fractal.variants_count = 1;
	fractal.no_pallet = 0;
	fractal.command_id = 1;
	fractal.type_i = type;
	return (fractal);
}

t_fractal	f_julia_3(t_complex_number formula, int type)
{
	t_fractal	fractal;

	fractal.id = 1;
	fractal.has_formula = 1;
	fractal.formula = formula;
	fractal.fractal_name = "Julia 3 set";
	fractal.fractol_function = &julia3_set;
	fractal.has_variants = 1;
	fractal.variants_count = 1;
	fractal.no_pallet = 0;
	fractal.command_id = 1;
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
	fractal.variants_count = 1;
	fractal.no_pallet = 0;
	fractal.command_id = 2;
	fractal.type_i = type;
	return (fractal);
}

t_fractal	f_mandelbrot_3(int type)
{
	t_fractal	fractal;

	fractal.id = 3;
	fractal.has_formula = 0;
	fractal.fractal_name = "Mandelbrot 3 set";
	fractal.fractol_function = &mandelbrot_3_set;
	fractal.has_variants = 1;
	fractal.variants_count = 1;
	fractal.no_pallet = 0;
	fractal.command_id = 2;
	fractal.type_i = type;
	return (fractal);
}

t_fractal	f_apollonian(int type)
{
	t_fractal	fractal;

	fractal.id = 4;
	fractal.has_formula = 0;
	fractal.fractal_name = "Apollonian gasket fractal";
	fractal.fractol_function = &apollonian_gasket_set;
	fractal.has_variants = 0;
	fractal.variants_count = 0;
	fractal.no_pallet = 1;
	fractal.command_id = 3;
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
	fractal.has_variants = 0;
	fractal.variants_count = 0;
	fractal.no_pallet = 0;
	fractal.command_id = 2;
	fractal.type_i = type;
	return (fractal);
}