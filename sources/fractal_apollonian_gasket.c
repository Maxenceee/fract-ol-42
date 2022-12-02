/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_apollonian_gasket.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:20:15 by mgama             #+#    #+#             */
/*   Updated: 2022/12/01 18:24:36 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	apollonian_gasket_set(t_data *mlx)
{
	t_circle	*circles_s;

	if (mlx->pallet_type % 2 == 0)
		circles_s = symmetric_set(
				(double)WINDOW_WIDTH / 2 - mlx->center_offset.x,
				(double)WINDOW_HEIGHT / 2 - mlx->center_offset.y,
				((double)WINDOW_HEIGHT / 2 - 100 + mlx->scale));
	else
		circles_s = a_symmetric_set(
				(double)WINDOW_WIDTH / 2 - mlx->center_offset.x,
				(double)WINDOW_HEIGHT / 2 - mlx->center_offset.y,
				((double)WINDOW_HEIGHT / 2 - 100 + mlx->scale));
	if (!circles_s)
		return ;
	clear_image(mlx);
	draw_gasket(circles_s, mlx);
}

void	draw_circle(t_circle circle, t_data *mlx)
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
		if (circle.center.x + x1 <= WINDOW_WIDTH && circle.center.x + x1 >= 0
			&& circle.center.y + y1 <= WINDOW_WIDTH
			&& circle.center.y + y1 >= 0)
			my_mlx_pixel_put(mlx, circle.center.x + x1,
				circle.center.y + y1, 0xFFFFFF);
		i += 0.1;
	}
}

void	clear_image(t_data *mlx)
{
	int		y;
	int		x;

	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(mlx, x, y, 0x000000);
		}
	}
}

void	draw_gasket(t_circle crls[3], t_data *mlx)
{
	t_circle	c4;
	t_circle	c5;

	c4 = get_adjacent(crls[0], crls[1], crls[2]);
	c5 = flip_circle(crls[0], crls[1], crls[2], c4);
	draw_circle(crls[0], mlx);
	draw_circle(crls[1], mlx);
	draw_circle(crls[2], mlx);
	draw_circle(c4, mlx);
	draw_circle(c5, mlx);
	recursive_circle(crls[0], crls[1], crls[2], c4, mlx);
	recursive_circle(c5, crls[1], crls[2], c4, mlx);
	free(crls);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
