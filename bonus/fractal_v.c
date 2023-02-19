/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:46:37 by mgama             #+#    #+#             */
/*   Updated: 2023/02/19 18:46:33 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	fractal_v(t_data *mlx, t_screen_dim s_dims)
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
			printf("%d\t%d\n", s_dims.left + x, s_dims.top + y);
			pix = calcule_fractal_v_series(
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

void	render_fractal_v(t_data *mlx, t_screen_dim s_dims, int x, int y)
{
	t_color	pallet;
	t_pixel	pix;

	pallet = mlx->pallets[mlx->pallet_type];
	pix = calcule_fractal_v_series(
			convert_corner_to_center(
				create_complex_number(s_dims.left + x, s_dims.top + y),
				mlx->center_offset, mlx->scale,
				create_complex_number(
					s_dims.center_x, s_dims.center_y)),
			mlx);
	my_mlx_pixel_put(mlx, s_dims.left + x, s_dims.top + y,
		get_color(mlx, pix, pallet));
}

t_pixel	calcule_fractal_v_series(t_complex_number point, t_data *mlx)
{
	t_complex_number	num;
	t_complex_number	temp_num;
	int					max_iter;
	int					i;
	int					mul;

	mul = mlx->fractal_list[mlx->current_fractal_type].formula_exp;
	num = create_complex_number(0, 0);
	max_iter = MAX_ITER;
	i = 0;
	while (modulus_complex_2(num) < 4 && i < max_iter)
	{
		// num.x = fabs(num.x);
		// num.y = fabs(num.y);
		temp_num = num;
		// num = complex_div(complex_rational_pow(temp_num, 2), complex_add(complex_rational_pow(temp_num, 3), point));
		// num = complex_add(complex_sinh(temp_num), complex_div(create_complex_number(1, 0), complex_mul(point, point)));
		// num = complex_div(create_complex_number(1, 0), complex_rational_pow(complex_add(temp_num, create_complex_number(point.x, point.y)), 3));
		// num = complex_add(complex_rational_pow(temp_num, 2), complex_sin(complex_rational_pow(point, 3)));
		// num = complex_add(complex_cos(temp_num), complex_div(create_complex_number(1, 0), complex_rational_pow(point, 2)));
		i++;
	}
	// printf("%+f\t%+f\t%+f\t%+f\n", point.x, point.y, num.x, num.y);
	return ((t_pixel){.coords = num, .i = i});
}
