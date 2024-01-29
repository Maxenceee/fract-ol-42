/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:37:46 by mgama             #+#    #+#             */
/*   Updated: 2024/01/29 16:05:44 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

inline void	mandelbrot_set(t_data *mlx, t_screen_dim s_dims)
{
	register int		y;
	register int		x;
	register t_color	pallet;
	register t_pixel	pix;

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
				get_color(mlx, pix, pallet));
		}
	}
}

inline void	render_mandelbrot_set(t_data *mlx, t_screen_dim s_dims, int x, int y)
{
	register t_color	pallet;
	register t_pixel	pix;

	pallet = mlx->pallets[mlx->pallet_type];
	pix = calcule_mandelbrot_series(
			convert_corner_to_center(
				create_complex_number(s_dims.left + x, s_dims.top + y),
				mlx->center_offset, mlx->scale,
				create_complex_number(
					s_dims.center_x, s_dims.center_y)),
			mlx);
	my_mlx_pixel_put(mlx, s_dims.left + x, s_dims.top + y,
		get_color(mlx, pix, pallet));
}

inline t_pixel	calcule_mandelbrot_series(t_complex_number point, t_data *mlx)
{
	register t_complex_number	num;
	register t_complex_number	temp_num;
	int							max_iter;
	int							i;
	int							mul;

	mul = mlx->fractal_list[mlx->current_fractal_type].formula_exp;
	num = create_complex_number(0, 0);
	max_iter = MAX_ITER;
	i = 0;
	while (modulus_complex_2(num) < (1 << 8) && i < max_iter)
	{
		temp_num = num;
		num = complex_add(complex_rational_pow(temp_num, mul), point);
		i++;
	}
	return ((t_pixel){.coords = num, .i = i});
}

inline t_complex_number	convert_corner_to_center(t_complex_number point,
	t_complex_number mouse_offset, double scale, t_complex_number mids)
{
	register t_complex_number	centered_point;

	centered_point.x = (point.x - mids.x) / scale + mouse_offset.x;
	centered_point.y = (point.y - mids.y) / scale + mouse_offset.y;
	return (centered_point);
}
