/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sinzc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:37:10 by mgama             #+#    #+#             */
/*   Updated: 2023/12/22 11:47:35 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	sinzc_set(t_data *mlx, t_screen_dim s_dims)
{
	int					y;
	int					x;
	t_color				pallet;
	t_pixel				pix;
	t_complex_number	u;

	y = -1;
	handle_exp_variants(mlx);
	if (mlx->fractal_list[mlx->current_fractal_type].formula_exp < 3)
		mlx->fractal_list[mlx->current_fractal_type].formula_exp = 3;
	pallet = mlx->pallets[mlx->pallet_type];
	while (++y < s_dims.height)
	{
		x = -1;
		while (++x < s_dims.width)
		{
			u = convert_corner_to_center(
					create_complex_number(s_dims.left + x, s_dims.top + y),
					mlx->center_offset, mlx->scale,
					create_complex_number(s_dims.center_x, s_dims.center_y));
			pix = calcule_sinzc_series(u, mlx->formula, mlx);
			my_mlx_pixel_put(mlx, s_dims.left + x, s_dims.top + y,
				get_color(mlx, pix, pallet));
		}
	}
}

void	render_sinzc_set(t_data *mlx, t_screen_dim s_dims, int x, int y)
{
	t_color				pallet;
	t_pixel				pix;
	t_complex_number	u;

	pallet = mlx->pallets[mlx->pallet_type];
	u = convert_corner_to_center(
			create_complex_number(s_dims.left + x, s_dims.top + y),
			mlx->center_offset,
			mlx->scale,
			create_complex_number(s_dims.center_x, s_dims.center_y));
	pix = calcule_sinzc_series(u, mlx->formula, mlx);
	my_mlx_pixel_put(mlx, s_dims.left + x, s_dims.top + y,
		get_color(mlx, pix, pallet));
}

t_pixel	calcule_sinzc_series(t_complex_number point,
	t_complex_number point_offset, t_data *mlx)
{
	t_complex_number	num;
	t_complex_number	temp_num;
	int					max_iter;
	int					i;
	int					mul;

	mul = mlx->fractal_list[mlx->current_fractal_type].formula_exp;
	num = create_complex_number(point.x, point.y);
	if (num.x == 0.f && num.y == 0.f)
		num = create_complex_number(1, 1);
	max_iter = get_max_iter_from_scale();
	i = 0;
	while (modulus_complex_2(num) < (1 << 8) && i < max_iter)
	{
		temp_num = num;
		num = complex_div(complex_sub(complex_rational_pow(temp_num, mul),
					point_offset), temp_num);
		i++;
	}
	return ((t_pixel){.coords = num, .i = i});
}

// num = complex_absv(complex_add(complex_rational_pow(temp_num, 2),
// 			complex_sin(complex_rational_pow(point_offset, 3)))); // ok
// num = complex_cos(complex_div(temp_num, point_offset)); // ok
// num = complex_add(complex_sinh(temp_num),
//			complex_div(create_complex_number(1, 0),
// 			complex_rational_pow(point_offset, 2)));