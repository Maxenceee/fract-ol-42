/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:37:46 by mgama             #+#    #+#             */
/*   Updated: 2024/02/06 19:01:36 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline void	mandelbrot_set(register t_data *mlx, register t_screen_dim s_dims)
{
	int					y;
	int					x;
	register t_color	pallet;
	register int		pix;

	y = -1;
	handle_exp_variants(mlx);
	pallet = mlx->pallets[mlx->pallet_type];
	while (++y < s_dims.height)
	{
		x = -1;
		while (++x < s_dims.width)
		{
			pix = calcule_mandelbrot_series(
					convert_corner_to_center(
						create_complex_number(s_dims.left + x, s_dims.top + y),
						mlx->center_offset, mlx->scale,
						create_complex_number(
							s_dims.center_x, s_dims.center_y)),
					mlx);
			my_mlx_pixel_put(mlx, s_dims.left + x, s_dims.top + y,
				get_color(pix, pallet.pallet, pallet.pallet_length));
		}
	}
}

inline int	calcule_mandelbrot_series(t_complex_number point, t_data *mlx)
{
	register t_complex_number	num;
	register t_complex_number	temp_num;
	int							i;

	num = create_complex_number(0, 0);
	i = 0;
	while (modulus_complex_2(num) < 4. && i < MAX_ITER)
	{
		temp_num = num;
		num = complex_add(
				complex_rational_pow(temp_num,
					mlx->fractal_list[mlx->curr_fractal_type].formula_exp),
				point);
		i++;
	}
	return (i);
}
