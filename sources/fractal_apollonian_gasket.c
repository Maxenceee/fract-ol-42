/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_apollonian_gasket.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:20:15 by mgama             #+#    #+#             */
/*   Updated: 2022/12/17 00:56:56 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	apollonian_gasket_set(t_data *mlx, t_screen_dim s_dims)
{
	t_circle	*circles_s;

	circles_s = symmetric_set(
			s_dims.center_x - mlx->center_offset.x * (mlx->scale / 2),
			s_dims.center_y - mlx->center_offset.y * (mlx->scale / 2),
			(s_dims.center_y - s_dims.height / 7 + (mlx->scale - INITIAL_SCALE)));
	// if (mlx->fractal_symmetry == 0)
	// else
	// 	circles_s = a_symmetric_set(
	// 			(double)WINDOW_WIDTH / 2 - mlx->center_offset.x * (mlx->scale / 2),
	// 			(double)WINDOW_HEIGHT / 2 - mlx->center_offset.y * (mlx->scale / 2),
	// 			((double)WINDOW_HEIGHT / 2 - 100 + mlx->scale));
	if (!circles_s)
		return ;
	clear_image(mlx, s_dims);
	draw_gasket(circles_s, mlx, s_dims);
}

void	draw_circle(t_circle circle, t_data *mlx, t_screen_dim s_dims)
{
	static const double	pi = 3.141592653589793;
	double				i;
	double				angle;
	double				x1;
	double				y1;

	i = 0;
	while (i < 360)
	{
		angle = i;
		x1 = circle.r * cos(angle * pi / 180);
		y1 = circle.r * sin(angle * pi / 180);
		if (circle.center.x + x1 <= s_dims.left + s_dims.width && circle.center.x + x1 >= s_dims.left 
			&& circle.center.y + y1 <= s_dims.top + s_dims.height
			&& circle.center.y + y1 >= s_dims.top)
			my_mlx_pixel_put(mlx, circle.center.x + x1,
				circle.center.y + y1, 0xFFFFFF);
		i += 0.1;
	}
}

void	clear_image(t_data *mlx, t_screen_dim s_dims)
{
	int		y;
	int		x;

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

void	draw_gasket(t_circle crls[3], t_data *mlx, t_screen_dim s_dims)
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
	recursive_circle(create_recursive_circle(crls[0], crls[1],
			crls[2], c4), mlx, s_dims);
	recursive_circle(create_recursive_circle(c5, crls[1], crls[2], c4), mlx, s_dims);
	free(crls);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
