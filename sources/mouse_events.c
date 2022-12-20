/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:30:45 by mgama             #+#    #+#             */
/*   Updated: 2022/12/20 18:48:23 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mouse_scroll(int button, t_complex_number mouse_pos,
	t_complex_number mids, t_data *mlx)
{
	if (button == 5)
	{
		if (mlx->scale == 0)
			mlx->scale = 1;
		else
			mlx->scale *= 1.5;
		if (mlx->mouse_offset)
			mlx->center_offset = aspect_scale(mlx, mouse_pos,
					mids, 0.5 / mlx->scale);
		mlx_update_image(mlx);
	}
	else if (button == 4)
	{
		if (INITIAL_SCALE + mlx->scale > 1)
			mlx->scale /= 1.5;
		if (mlx->mouse_offset)
			mlx->center_offset = aspect_scale(mlx, mouse_pos,
					mids, -1. / 3. / mlx->scale);
		mlx_update_image(mlx);
	}
}

int	mouse_event(int button, int x, int y, void *param)
{
	t_data				*mlx;
	t_complex_number	temp_pos;
	t_complex_number	mids;

	mlx = (t_data *)param;
	if (mlx->is_home)
	{
		mouse_home_event(mlx, button, x, y);
		return (0);
	}
	mids = create_complex_number((double)WINDOW_WIDTH / 2,
			(double)WINDOW_HEIGHT / 2);
	temp_pos = create_complex_number(x, y);
	mouse_scroll(button, temp_pos, mids, mlx);
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_data		*mlx;
	double		rx;
	double		ry;

	mlx = (t_data *)param;
	if (mlx->is_home)
		return (0);
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		mlx->mouse_clicked = 0;
	if (mlx->mouse_lock == 0 && mlx->mouse_clicked == 0)
	{
		if (!mlx->fractal_list[mlx->current_fractal_type].has_formula)
			return (0);
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
			mlx_update_image(mlx);
		}
	}
	else if (mlx->mouse_clicked)
	{
		mlx->center_offset.x = (mlx->mouse_pos_save.x - (double)x) \
				/ mlx->scale;
		mlx->center_offset.y = (mlx->mouse_pos_save.y - (double)y) \
				/ mlx->scale;
		mlx_update_image(mlx);
	}
	return (0);
}

int	mouse_down_event(int button, int x, int y, void *param)
{
	t_data		*mlx;

	mlx = (t_data *)param;
	if (button == 1 && !mlx->is_home)
	{
		mlx->mouse_pos_save = create_complex_number(
				(mlx->center_offset.x * mlx->scale) + x,
				(mlx->center_offset.y * mlx->scale) + y);
		mlx->mouse_clicked = 1;
	}
	mouse_event(button, x, y, param);
	return (0);
}

int	mouse_up_event(int button, int x, int y, void *param)
{
	t_data		*mlx;

	mlx = (t_data *)param;
	if (button == 1)
		mlx->mouse_clicked = 0;
	return (0);
}
