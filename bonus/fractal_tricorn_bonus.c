/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_tricorn_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:03:08 by mgama             #+#    #+#             */
/*   Updated: 2024/02/06 18:54:49 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

inline void	fractal_tricorn(register t_data *mlx, register t_screen_dim s_dims)
{
	int					y;
	int					x;
	register t_pixel	pix;

	y = -1;
	handle_exp_variants(mlx);
	while (++y < s_dims.height)
	{
		x = -1;
		while (++x < s_dims.width)
		{
			pix = calcule_tricorn_series(
					convert_corner_to_center(
						create_complex_number(s_dims.left + x, s_dims.top + y),
						mlx->center_offset, mlx->scale,
						create_complex_number(
							s_dims.center_x, s_dims.center_y)),
					mlx);
			my_mlx_pixel_put(mlx, s_dims.left + x, s_dims.top + y,
				get_color(mlx, pix, mlx->pallets[mlx->pallet_type]));
		}
	}
}

inline void	render_fractal_tricorn(register t_data *mlx,
	register t_screen_dim s_dims, int x, int y)
{
	register t_pixel	pix;

	pix = calcule_tricorn_series(
			convert_corner_to_center(
				create_complex_number(s_dims.left + x, s_dims.top + y),
				mlx->center_offset, mlx->scale,
				create_complex_number(
					s_dims.center_x, s_dims.center_y)),
			mlx);
	my_mlx_pixel_put(mlx, s_dims.left + x, s_dims.top + y,
		get_color(mlx, pix, mlx->pallets[mlx->pallet_type]));
}

inline t_pixel	calcule_tricorn_series(t_complex_number point, t_data *mlx)
{
	register t_complex_number	num;
	register t_complex_number	temp_num;
	int							i;

	(void)(mlx);
	num = create_complex_number(0, 0);
	i = 0;
	while (modulus_complex_2(num) < (1 << 4) && i < MAX_ITER)
	{
		temp_num = num;
		num.x = temp_num.x * temp_num.x - temp_num.y * temp_num.y + point.x;
		num.y = -2. * temp_num.x * temp_num.y + point.y;
		i++;
	}
	return ((t_pixel){.coords = num, .i = i});
}
