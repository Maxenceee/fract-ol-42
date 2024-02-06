/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:28:46 by mgama             #+#    #+#             */
/*   Updated: 2024/02/06 19:29:22 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

inline void	julia_set(register t_data *mlx, register t_screen_dim s_d)
{
	int							y;
	int							x;
	register t_pixel			pix;

	y = -1;
	handle_exp_variants(mlx);
	while (++y < s_d.height)
	{
		x = -1;
		while (++x < s_d.width)
		{
			pix = calcule_julia_series(
					convert_corner_to_center(
						create_complex_number(s_d.left + x, s_d.top + y),
						mlx->center_offset,
						mlx->scale,
						create_complex_number(s_d.center_x, s_d.center_y)),
					mlx->formula, mlx);
			my_mlx_pixel_put(mlx, s_d.left + x, s_d.top + y,
				get_color(mlx, pix, mlx->pallets[mlx->pallet_type]));
		}
	}
}

inline void	render_julia_set(register t_data *mlx, register t_screen_dim s_dims,
	int x, int y)
{
	register t_pixel			pix;

	pix = calcule_julia_series(
			convert_corner_to_center(
				create_complex_number(s_dims.left + x, s_dims.top + y),
				mlx->center_offset,
				mlx->scale,
				create_complex_number(s_dims.center_x, s_dims.center_y)),
			mlx->formula, mlx);
	my_mlx_pixel_put(mlx, s_dims.left + x, s_dims.top + y,
		get_color(mlx, pix, mlx->pallets[mlx->pallet_type]));
}

inline t_pixel	calcule_julia_series(t_complex_number point,
	t_complex_number point_offset, t_data *mlx)
{
	register t_complex_number	num;
	register t_complex_number	temp_num;
	int							i;

	num = create_complex_number(point.x, point.y);
	i = 0;
	while (modulus_complex_2(num) < (1 << 8) && i < MAX_ITER)
	{
		temp_num = num;
		num = complex_add(
				complex_rational_pow(temp_num,
					mlx->fractal_list[mlx->curr_fractal_type].formula_exp),
				point_offset);
		i++;
	}
	return ((t_pixel){.coords = num, .i = i});
}

inline int	handle_exp_variants(t_data *mlx)
{
	if (mlx->next_variant == 1)
		mlx->fractal_list[mlx->curr_fractal_type].formula_exp++;
	if (mlx->prev_variant == 1
		&& mlx->fractal_list[mlx->curr_fractal_type].formula_exp
		> mlx->fractal_list[mlx->curr_fractal_type].min_exp)
		mlx->fractal_list[mlx->curr_fractal_type].formula_exp--;
	return (mlx->fractal_list[mlx->curr_fractal_type].formula_exp);
}
