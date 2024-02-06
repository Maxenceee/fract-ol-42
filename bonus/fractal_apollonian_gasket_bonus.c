/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_apollonian_gasket_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:20:15 by mgama             #+#    #+#             */
/*   Updated: 2024/02/06 18:40:06 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

inline void	apollonian_gasket_set(t_data *mlx, t_screen_dim s_dims)
{
	register t_circle	*circles_s;

	circles_s = handle_gasket_variants(mlx, s_dims);
	if (!circles_s)
		return ;
	clear_image(mlx, s_dims);
	draw_gasket(circles_s, mlx, s_dims);
}

inline void	draw_circle(t_circle circle, t_data *mlx, t_screen_dim s_dims)
{
	static const double	pi = 3.141592653589793;
	register double		i;
	register double		angle;
	register double		y1;
	register double		x1;

	i = 0;
	while (i < 360)
	{
		angle = i;
		x1 = circle.r * cos(angle * pi / 180);
		y1 = circle.r * sin(angle * pi / 180);
		if (circle.center.x + x1 <= s_dims.left + s_dims.width
			&& circle.center.x + x1 >= s_dims.left
			&& circle.center.y + y1 <= s_dims.top + s_dims.height
			&& circle.center.y + y1 >= s_dims.top)
			my_mlx_pixel_put(mlx, circle.center.x + x1,
				circle.center.y + y1, 0xFFFFFF);
		i += 0.1;
	}
}

inline void	clear_image(t_data *mlx, t_screen_dim s_dims)
{
	register int	y;
	register int	x;

	y = -1;
	while (++y < s_dims.height)
	{
		x = -1;
		while (++x < s_dims.width)
		{
			my_mlx_pixel_put(mlx, s_dims.left + x, s_dims.top + y, 0x000000);
		}
	}
}

inline void	draw_gasket(register t_circle *crls, t_data *mlx,
	register t_screen_dim s_dims)
{
	t_circle	c4;
	t_circle	c5;

	c4 = get_adjacent(crls[0], crls[1], crls[2]);
	c5 = flip_circle(crls[0], crls[1], crls[2], c4);
	draw_circle(crls[0], mlx, s_dims);
	draw_circle(crls[1], mlx, s_dims);
	draw_circle(crls[2], mlx, s_dims);
	draw_circle(c4, mlx, s_dims);
	draw_circle(c5, mlx, s_dims);
	recursive_circle(
		create_recursive_circle(crls[0], crls[1], crls[2], c4), mlx, s_dims);
	recursive_circle(
		create_recursive_circle(c5, crls[1], crls[2], c4), mlx, s_dims);
	free(crls);
}

inline t_circle	*handle_gasket_variants(t_data *mlx, t_screen_dim s_dims)
{
	static int	is_a;

	if (mlx->next_variant || mlx->prev_variant)
		is_a = !is_a;
	if (is_a)
		return (a_symmetric_set(
				s_dims.center_x - mlx->center_offset.x * (mlx->scale * 0.5),
				s_dims.center_y - mlx->center_offset.y * (mlx->scale * 0.5),
				((s_dims.height * 0.5) - s_dims.height / 5
					+ (mlx->scale * 0.5))));
	return (symmetric_set(
			s_dims.center_x - mlx->center_offset.x * (mlx->scale * 0.5),
			s_dims.center_y - mlx->center_offset.y * (mlx->scale * 0.5),
			((s_dims.height * 0.5) - s_dims.height / 5
				+ (mlx->scale * 0.5))));
}
