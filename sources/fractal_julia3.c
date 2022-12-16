/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:55:16 by mgama             #+#    #+#             */
/*   Updated: 2022/12/16 15:48:44 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia3_set(t_data *mlx, t_screen_dim s_dims)
{
	int					y;
	int					x;
	t_color				pallet;
	int					pix;
	t_complex_number	u;

	y = -1;
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
			pix = calule_julia_3_series(u, mlx->formula, mlx->scale);
			my_mlx_pixel_put(mlx, s_dims.left + x, s_dims.top + y,
				get_color(pix, pallet.pallet, pallet.pallet_length));
		}
	}
}

int	calule_julia_3_series(t_complex_number point,
	t_complex_number point_offset, double scale)
{
	t_complex_number	num;
	t_complex_number	temp_num;
	int					max_iter;
	int					i;

	temp_num = create_complex_number(0, 0);
	num = create_complex_number(point.x, point.y);
	max_iter = get_max_iter_from_scale(scale);
	i = 0;
	while (modulus_complex_2(num) < 4. && i < max_iter)
	{
		temp_num = num;
		num.x = temp_num.x * temp_num.x * temp_num.x - 3 * temp_num.x
			* temp_num.y * temp_num.y + point_offset.x;
		num.y = 3. * temp_num.x * temp_num.x * temp_num.y - temp_num.y
			* temp_num.y * temp_num.y + point_offset.y;
		i++;
	}
	return (i);
}
