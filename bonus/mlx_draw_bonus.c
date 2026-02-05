/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:12:24 by mgama             #+#    #+#             */
/*   Updated: 2026/02/05 23:31:01 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

inline void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	((int *)data->addr)[y * (data->line_length >> 2) + x] = color;
}

inline t_complex_number	aspect_scale(t_data *mlx, t_complex_number mouse_pos,
	t_complex_number mids, double scale)
{
	return (create_complex_number(
			(mouse_pos.x - mids.x) * scale + mlx->center_offset.x,
			(mouse_pos.y - mids.y) * scale + mlx->center_offset.y
		));
}
