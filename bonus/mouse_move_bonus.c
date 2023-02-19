/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:33:15 by mgama             #+#    #+#             */
/*   Updated: 2023/02/19 02:03:25 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	mouse_move(int x, int y, void *param)
{
	t_data		*mlx;

	mlx = (t_data *)param;
	if (mlx->is_home)
		return (0);
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		mlx->mouse_clicked = 0;
	if (mlx->mouse_lock == 0 && mlx->mouse_clicked == 0)
		handle_on_mouse_lock(x, y, mlx);
	else if (mlx->mouse_clicked)
	{
		mlx->center_offset.x = (mlx->mouse_pos_save.x - (double)x) \
				/ mlx->scale;
		mlx->center_offset.y = (mlx->mouse_pos_save.y - (double)y) \
				/ mlx->scale;
		mlx_update_image_multitp(mlx);
	}
	return (0);
}

void	handle_on_mouse_lock(int x, int y, t_data *mlx)
{
	double		rx;
	double		ry;

	if (!mlx->fractal_list[mlx->current_fractal_type].has_formula)
		return ;
	rx = 1. / WINDOW_WIDTH * x;
	ry = 1. / WINDOW_HEIGHT * y;
	if (rx > 0. && rx < 1. && ry > 0. && ry < 1.)
	{
		if (mlx->need_save == 1)
		{
			mlx->need_save = 0;
			mlx->saved_mouse.x = rx;
			mlx->saved_mouse.y = ry;
		}
		mlx->formula.x = (mlx->saved_formula.x
				- mlx->saved_mouse.x) + rx;
		mlx->formula.y = (mlx->saved_formula.y
				- mlx->saved_mouse.y) + ry;
		mlx->fractal_list[mlx->current_fractal_type].formula = mlx->formula;
		mlx_update_image_multitp(mlx);
	}
}
