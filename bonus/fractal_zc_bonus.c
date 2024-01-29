/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_zc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:28:46 by mgama             #+#    #+#             */
/*   Updated: 2024/01/29 16:06:44 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

inline void	zc_set(t_data *mlx, t_screen_dim s_dims)
{
	register int				y;
	register int				x;
	register t_color			pallet;
	register t_pixel			pix;
	register t_complex_number	u;

	y = -1;
	handle_exp_variants(mlx);
	pallet = mlx->pallets[mlx->pallet_type];
	while (++y < s_dims.height)
	{
		x = -1;
		while (++x < s_dims.width)
		{
			u = convert_corner_to_center(
					create_complex_number(s_dims.left + x, s_dims.top + y),
					mlx->center_offset,
					mlx->scale,
					create_complex_number(s_dims.center_x, s_dims.center_y));
			pix = calcule_zc_series(u, mlx->formula, mlx);
			my_mlx_pixel_put(mlx, s_dims.left + x, s_dims.top + y,
				get_color(mlx, pix, pallet));
		}
	}
}

inline void	render_zc_set(t_data *mlx, t_screen_dim s_dims, int x, int y)
{
	register t_color			pallet;
	register t_pixel			pix;
	register t_complex_number	u;

	pallet = mlx->pallets[mlx->pallet_type];
	u = convert_corner_to_center(
			create_complex_number(s_dims.left + x, s_dims.top + y),
			mlx->center_offset,
			mlx->scale,
			create_complex_number(s_dims.center_x, s_dims.center_y));
	pix = calcule_zc_series(u, mlx->formula, mlx);
	my_mlx_pixel_put(mlx, s_dims.left + x, s_dims.top + y,
		get_color(mlx, pix, pallet));
}

inline t_pixel	calcule_zc_series(t_complex_number point,
	t_complex_number point_offset, t_data *mlx)
{
	register t_complex_number	num;
	register t_complex_number	temp_num;
	int							max_iter;
	int							i;

	(void)(mlx);
	num = create_complex_number(point.x, point.y);
	max_iter = get_max_iter_from_scale();
	i = 0;
	while (modulus_complex_2(num) < (1 << 8) && i < max_iter)
	{
		temp_num = num;
		num = complex_add(complex_cos(temp_num),
				complex_div(create_complex_number(1, 0), point_offset));
		i++;
	}
	return ((t_pixel){.coords = num, .i = i});
}
