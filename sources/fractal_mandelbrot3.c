/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:52:14 by mgama             #+#    #+#             */
/*   Updated: 2022/12/16 19:46:38 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot_3_set(t_data *mlx, t_screen_dim s_dims)
{
	int		y;
	int		x;
	t_color	pallet;
	int		pix;

	y = -1;
	pallet = mlx->pallets[mlx->pallet_type];
	while (++y < s_dims.height)
	{
		x = -1;
		while (++x < s_dims.width)
		{
			pix = calule_mandelbrot_3_series(
					convert_corner_to_center(
						create_complex_number(s_dims.left + x, s_dims.top + y),
						mlx->center_offset, mlx->scale,
						create_complex_number(s_dims.center_x, s_dims.center_y)));
			my_mlx_pixel_put(mlx, s_dims.left + x, s_dims.top + y,
				get_color(pix, pallet.pallet, pallet.pallet_length));
		}
	}
}

int	calule_mandelbrot_3_series(t_complex_number point)
{
	t_complex_number	num;
	t_complex_number	temp_num;
	int					max_iter;
	int					i;

	temp_num = create_complex_number(0, 0);
	num = create_complex_number(0, 0);
	max_iter = MAX_ITER;
	i = 0;
	while (modulus_complex_2(num) < 4. && i < max_iter)
	{
		temp_num = num;
		// num.x = temp_num.x * temp_num.x * temp_num.x - 3 * temp_num.x
		// 	* temp_num.y * temp_num.y + point.x;
		// num.y = 3. * temp_num.x * temp_num.x * temp_num.y - temp_num.y
		// 	* temp_num.y * temp_num.y + point.y;
		num = complex_add(complex_mul(complex_mul(temp_num, temp_num), temp_num), point); // 3
		// num = complex_add(complex_mul(complex_mul(complex_mul(temp_num, temp_num), complex_mul(temp_num, temp_num)), temp_num), point); // 5
		i++;
	}
	return (i);
}
