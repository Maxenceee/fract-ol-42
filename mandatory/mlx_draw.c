/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:12:24 by mgama             #+#    #+#             */
/*   Updated: 2024/02/06 18:44:18 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	((int *)data->addr)[y * (data->line_length >> 2) + x] = color;
}

void	mlx_update_image(t_data *mlx)
{
	(*mlx->fractal_list[mlx
			->curr_fractal_type].fractol_function)(mlx, mlx->screen_dims);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
}

inline t_complex_number	aspect_scale(t_data *mlx, t_complex_number mouse_pos,
	t_complex_number mids, double scale)
{
	return (create_complex_number(
			(mouse_pos.x - mids.x) * scale + mlx->center_offset.x,
			(mouse_pos.y - mids.y) * scale + mlx->center_offset.y
		));
}
