/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:28:46 by mgama             #+#    #+#             */
/*   Updated: 2022/11/28 17:12:10 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia_set(t_data *mlx)
{
	int		y;
	int		x;
	t_color	pallet;
	int		pix;

	y = -1;
	pallet = mlx->pallets[mlx->pallet_type];
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			t_complex_number u = convert_corner_to_center(
				create_complex_number(x, y),
				mlx->center_offset,
				mlx->scale);
			pix = calule_julia_series(u, mlx->formula);
			my_mlx_pixel_put(mlx, x, y, get_color(pix, pallet.pallet, pallet.pallet_length));
		}
	}
}

int	calule_julia_series(t_complex_number point, t_complex_number point_offset)
{
	t_complex_number	num;
	t_complex_number	temp_num;
	int					max_iter;
	int					i;
	
	temp_num = create_complex_number(0, 0);
	num = create_complex_number(point.x, point.y);
	max_iter = MAX_ITER;
	i = 0;
	while (modulus_complex_2(num) < 4. && i < max_iter)
	{
		temp_num = num;
		num.x = temp_num.x * temp_num.x - temp_num.y * temp_num.y + point_offset.x;
		num.y = 2. * temp_num.x * temp_num.y + point_offset.y;
		i++;
	}
	return (i);
}

t_complex_number	convert_corner_to_center(t_complex_number point, t_complex_number mouse_offset, double scale)
{
	t_complex_number centered_point;

	centered_point.x = (point.x + (mouse_offset.x * 1) - (WINDOW_WIDTH / 2)) / (INITIAL_SCALE + scale);
	centered_point.y = (point.y + (mouse_offset.y * 1) - (WINDOW_HEIGHT / 2)) / (INITIAL_SCALE + scale);
	
	// centered_point.x = (point.x - (WINDOW_WIDTH / 2) * (1 / INITIAL_SCALE + scale)) / (WINDOW_WIDTH / 2 + mouse_offset.x);
	// centered_point.y = (point.y - (WINDOW_HEIGHT / 2) * (1 / INITIAL_SCALE + scale)) / (WINDOW_HEIGHT / 2 + mouse_offset.y);
	

	// centered_point.y = (point.y - (WINDOW_HEIGHT / 2)) / (INITIAL_SCALE + scale);
	return (centered_point);
}

t_complex_number	get_mouse_offset_from_center(t_complex_number point)
{
	t_complex_number corner_point;

	corner_point.x = (point.x - WINDOW_WIDTH / 2) * 1;
	corner_point.y = (point.y - WINDOW_HEIGHT / 2) * 1;
	return (corner_point);
}
