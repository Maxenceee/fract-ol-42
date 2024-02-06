/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_zc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:28:46 by mgama             #+#    #+#             */
/*   Updated: 2024/02/06 18:56:23 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

inline void	zc_set(register t_data *mlx, register t_screen_dim s_d)
{
	int					y;
	int					x;
	register t_pixel	pix;

	y = -1;
	handle_exp_variants(mlx);
	while (++y < s_d.height)
	{
		x = -1;
		while (++x < s_d.width)
		{
			pix = calcule_zc_series(
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

inline void	render_zc_set(register t_data *mlx, register t_screen_dim s_dims,
	int x, int y)
{
	register t_pixel			pix;

	pix = calcule_zc_series(
			convert_corner_to_center(
				create_complex_number(s_dims.left + x, s_dims.top + y),
				mlx->center_offset,
				mlx->scale,
				create_complex_number(s_dims.center_x, s_dims.center_y)),
			mlx->formula, mlx);
	my_mlx_pixel_put(mlx, s_dims.left + x, s_dims.top + y,
		get_color(mlx, pix, mlx->pallets[mlx->pallet_type]));
}

inline t_pixel	calcule_zc_series(t_complex_number point,
	t_complex_number point_offset, t_data *mlx)
{
	register t_complex_number	num;
	register t_complex_number	temp_num;
	int							i;

	(void)(mlx);
	num = create_complex_number(point.x, point.y);
	i = 0;
	while (modulus_complex_2(num) < (1 << 8) && i < MAX_ITER)
	{
		temp_num = num;
		num = complex_add(complex_cos(temp_num),
				complex_div(create_complex_number(1, 0), point_offset));
		i++;
	}
	return ((t_pixel){.coords = num, .i = i});
}
