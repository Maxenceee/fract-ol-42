/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_burningship_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:56:17 by mgama             #+#    #+#             */
/*   Updated: 2023/03/22 15:06:54 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	burningship_set(t_data *mlx, t_screen_dim s_dims)
{
	int		y;
	int		x;
	t_color	pallet;
	t_pixel	pix;

	y = -1;
	handle_exp_variants(mlx);
	pallet = mlx->pallets[mlx->pallet_type];
	while (++y < s_dims.height)
	{
		x = -1;
		while (++x < s_dims.width)
		{
			pix = calcule_burningship_series(
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

void	render_burningship_set(t_data *mlx, t_screen_dim s_dims, int x, int y)
{
	t_color	pallet;
	t_pixel	pix;

	pallet = mlx->pallets[mlx->pallet_type];
	pix = calcule_burningship_series(
			convert_corner_to_center(
				create_complex_number(s_dims.left + x, s_dims.top + y),
				mlx->center_offset, mlx->scale,
				create_complex_number(
					s_dims.center_x, s_dims.center_y)),
			mlx);
	my_mlx_pixel_put(mlx, s_dims.left + x, s_dims.top + y,
		get_color(mlx, pix, pallet));
}

t_pixel	calcule_burningship_series(t_complex_number point, t_data *mlx)
{
	t_complex_number	num;
	t_complex_number	temp_num;
	int					max_iter;
	int					i;
	int					mul;

	mul = mlx->fractal_list[mlx->current_fractal_type].formula_exp;
	num = create_complex_number(0, 0);
	max_iter = get_max_iter_from_scale();
	i = 0;
	while (modulus_complex_2(num) < (1 << 8) && i < max_iter)
	{
		num.x = fabs(num.x);
		num.y = fabs(num.y);
		temp_num = num;
		num = complex_add(complex_rational_pow(temp_num, mul), point);
		i++;
	}
	return ((t_pixel){.coords = num, .i = i});
}
