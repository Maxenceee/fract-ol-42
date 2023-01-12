/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:28:46 by mgama             #+#    #+#             */
/*   Updated: 2023/01/12 16:47:57 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia_set(t_data *mlx, t_screen_dim s_dims)
{
	int					y;
	int					x;
	t_color				pallet;
	int					pix;
	t_complex_number	u;

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
			pix = calule_julia_series(u, mlx->formula, mlx->scale, mlx);
			my_mlx_pixel_put(mlx, s_dims.left + x, s_dims.top + y,
				get_color(pix, pallet.pallet, pallet.pallet_length));
		}
	}
}

int	calule_julia_series(t_complex_number point,
	t_complex_number point_offset, double scale, t_data *mlx)
{
	t_complex_number	num;
	t_complex_number	temp_num;
	int					max_iter;
	int					i;
	int					mul;

	mul = mlx->fractal_list[mlx->current_fractal_type].formula_exp;
	num = create_complex_number(point.x, point.y);
	max_iter = get_max_iter_from_scale(scale);
	i = 0;
	while (modulus_complex_2(num) < 4. && i < max_iter)
	{
		temp_num = num;
		num = complex_add(complex_rational_pow(temp_num, mul), point_offset);
		i++;
	}
	return (i);
}

int	handle_exp_variants(t_data *mlx)
{
	if (mlx->next_variant == 1)
		mlx->fractal_list[mlx->current_fractal_type].formula_exp++;
	if (mlx->prev_variant == 1
		&& mlx->fractal_list[mlx->current_fractal_type].formula_exp > 1)
		mlx->fractal_list[mlx->current_fractal_type].formula_exp--;
	return (mlx->fractal_list[mlx->current_fractal_type].formula_exp);
}

int	get_max_iter_from_scale(double scale)
{
	UNUSED(scale);
	return (MAX_ITER);
}

t_complex_number	convert_corner_to_center(t_complex_number point,
	t_complex_number mouse_offset, double scale, t_complex_number mids)
{
	t_complex_number	centered_point;

	centered_point.x = (point.x - mids.x) / scale + mouse_offset.x;
	centered_point.y = (point.y - mids.y) / scale + mouse_offset.y;
	return (centered_point);
}
