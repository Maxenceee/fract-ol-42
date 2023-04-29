/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_list_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:17:33 by mgama             #+#    #+#             */
/*   Updated: 2023/04/30 00:10:37 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

t_fractal	f_julia(t_complex_number formula, int type)
{
	t_fractal	fractal;

	fractal.id = 0;
	fractal.mfvar = 1;
	fractal.has_formula = 1;
	fractal.formula = formula;
	fractal.fractal_name = "Julia set";
	fractal.fractol_function = &render_julia_set;
	fractal.fractol_function_nothp = &julia_set;
	fractal.has_variants = 1;
	fractal.formula_exp = 2;
	fractal.no_pallet = 0;
	fractal.command_id = 1;
	fractal.type_i = type;
	return (fractal);
}

t_fractal	f_mandelbrot(int type)
{
	t_fractal	fractal;

	fractal.id = 2;
	fractal.mfvar = 1;
	fractal.has_formula = 0;
	fractal.fractal_name = "Mandelbrot set";
	fractal.fractol_function = &render_mandelbrot_set;
	fractal.fractol_function_nothp = &mandelbrot_set;
	fractal.has_variants = 1;
	fractal.formula_exp = 2;
	fractal.no_pallet = 0;
	fractal.command_id = 2;
	fractal.type_i = type;
	return (fractal);
}

t_fractal	f_apollonian(int type)
{
	t_fractal	fractal;

	fractal.id = 4;
	fractal.mfvar = 0;
	fractal.has_formula = 0;
	fractal.fractal_name = "Apollonian gasket";
	fractal.fractol_function = NULL;
	fractal.fractol_function_nothp = &apollonian_gasket_set;
	fractal.has_variants = 1;
	fractal.formula_exp = -1;
	fractal.no_pallet = 1;
	fractal.command_id = 3;
	fractal.type_i = type;
	return (fractal);
}

t_fractal	f_burningship(int type)
{
	t_fractal	fractal;

	fractal.id = 5;
	fractal.mfvar = 1;
	fractal.has_formula = 0;
	fractal.fractal_name = "Burningship set";
	fractal.fractol_function = &render_burningship_set;
	fractal.fractol_function_nothp = &burningship_set;
	fractal.has_variants = 1;
	fractal.formula_exp = 2;
	fractal.no_pallet = 0;
	fractal.command_id = 2;
	fractal.type_i = type;
	return (fractal);
}

t_fractal	f_fractal_tricorn(int type)
{
	t_fractal	fractal;

	fractal.id = 6;
	fractal.mfvar = 1;
	fractal.has_formula = 0;
	fractal.fractal_name = "Tricorn";
	fractal.fractol_function = &render_fractal_tricorn;
	fractal.fractol_function_nothp = &fractal_tricorn;
	fractal.has_variants = 1;
	fractal.formula_exp = 2;
	fractal.no_pallet = 0;
	fractal.command_id = 2;
	fractal.type_i = type;
	return (fractal);
}

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
	fractal.has_variants = 0;
	fractal.formula_exp = -1;
	fractal.no_pallet = 0;
	fractal.command_id = 2;
	fractal.type_i = type;
	return (fractal);
}
