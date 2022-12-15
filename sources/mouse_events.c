/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:30:45 by mgama             #+#    #+#             */
/*   Updated: 2022/12/15 01:05:47 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex_number	aspect_scale(t_data *mlx, t_complex_number mouse_pos,
	t_complex_number mids, double scale)
{
	return (create_complex_number(
			(mouse_pos.x - mids.x) * scale + mlx->center_offset.x,
			(mouse_pos.y - mids.y) * scale + mlx->center_offset.y
		));
}

void	mouse_scroll(int button, t_complex_number mouse_pos,
	t_complex_number mids, t_data *mlx)
{
	if (button == 5)
	{
		if (mlx->scale == 0)
			mlx->scale = 1;
		else
			mlx->scale *= 1.5;
		fflush(NULL);
		if (mlx->mouse_offset)
			mlx->center_offset = aspect_scale(mlx, mouse_pos,
					mids, 0.5 / mlx->scale);
		switch_mlx_image(mlx);
	}
	else if (button == 4)
	{
		if (INITIAL_SCALE + mlx->scale > 1)
			mlx->scale /= 1.5;
		if (mlx->mouse_offset)
			mlx->center_offset = aspect_scale(mlx, mouse_pos,
					mids, -1. / 3. / mlx->scale);
		switch_mlx_image(mlx);
	}
}

int	mouse_event(int button, int x, int y, void *param)
{
	t_data				*mlx;
	t_complex_number	temp_pos;
	t_complex_number	mids;

	mlx = (t_data *)param;
	mids = create_complex_number((double)WINDOW_WIDTH / 2,
			(double)WINDOW_HEIGHT / 2);
	temp_pos = create_complex_number(x, y);
	mouse_scroll(button, temp_pos, mids, mlx);
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_data	*mlx;
	double	rx;
	double	ry;

	mlx = (t_data *)param;
	if (mlx->mouse_lock == 0)
	{
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
					- mlx->saved_mouse.y) + ry ;
			switch_mlx_image(mlx);
		}
	}
	return (0);
}
