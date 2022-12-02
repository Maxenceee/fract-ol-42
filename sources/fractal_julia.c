/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:28:46 by mgama             #+#    #+#             */
/*   Updated: 2022/12/01 19:18:16 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia_set(t_data *mlx)
{
	int					y;
	int					x;
	t_color				pallet;
	int					pix;
	t_complex_number	u;

	// u = convert_corner_to_center(
	// 			create_complex_number(360, 370),
	// 			create_complex_number(0, 0),
	// 			30);
	// return ;
	y = -1;
	pallet = mlx->pallets[mlx->pallet_type];
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			u = convert_corner_to_center(
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
	t_complex_number	centered_point;
	t_complex_number	f_centered_point;
	double				midx;
	double				midy;
	double				f_scale;

	midx = (double)WINDOW_WIDTH / 2;
	midy = (double)WINDOW_HEIGHT / 2;
	f_scale = (INITIAL_SCALE + scale);
	
	// f_centered_point.x = f_scale * (mouse_offset.x - midx) / midx * 0.5;
	// f_centered_point.y = f_scale * (mouse_offset.y - midy) / midy * 0.5;

	// print_complex(f_centered_point);

	centered_point.x = (point.x + mouse_offset.x - midx) / f_scale;
	centered_point.y = (point.y + mouse_offset.y - midy) / f_scale;
	
	// centered_point.x = (point.x - midx) * f_scale * (1 / midx) + mouse_offset.x;
	// centered_point.y = (point.y - midy) * f_scale * (1 / midy) + mouse_offset.y;
	
	// print_complex(f_centered_point);
	// print_complex(centered_point);
	// print_complex(create_complex_number(f_centered_point.x - centered_point.x, f_centered_point.y - centered_point.y));

	// centered_point.x = (point.x + (f_centered_point.x + centered_point.x) - midx) / f_scale;
	// centered_point.y = (point.y + (f_centered_point.y + centered_point.y) - midy) / f_scale;
	// print_complex(centered_point);
	
	// centered_point.x = (point.x + ((mouse_offset.x / f_scale) * midx) - midx) / f_scale;
	// centered_point.y = (point.y + ((mouse_offset.y / f_scale) * midy) - midy) / f_scale;
	
	// centered_point.x = (point.x + (mouse_offset.x * ((point.x - mouse_offset.x) / f_scale)) - midx) / f_scale;
	// centered_point.y = (point.y + (mouse_offset.y * ((point.y - mouse_offset.y) / f_scale)) - midy) / f_scale;

	return (centered_point);
}

t_complex_number	get_mouse_offset_from_center(t_complex_number point)
{
	t_complex_number corner_point;

	corner_point.x = (point.x - WINDOW_WIDTH / 2) * 1;
	corner_point.y = (point.y - WINDOW_HEIGHT / 2) * 1;
	return (corner_point);
}
