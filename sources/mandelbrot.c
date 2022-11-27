/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:37:46 by mgama             #+#    #+#             */
/*   Updated: 2022/11/27 23:44:20 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot_set(t_data *mlx)
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
			pix = calule_mandelbrot_series(convert_corner_to_center(create_complex_number(x, y), mlx->center_offset, mlx->scale));
			my_mlx_pixel_put(mlx, x, y, get_color(pix, pallet.pallet, pallet.pallet_length));
		}
	}
}

int	calule_mandelbrot_series(t_complex_number point)
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
		num.x = temp_num.x * temp_num.x - temp_num.y * temp_num.y + point.x;
		num.y = 2. * temp_num.x * temp_num.y + point.y;
		i++;
	}
	return (i);
}