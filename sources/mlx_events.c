/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:13:26 by mgama             #+#    #+#             */
/*   Updated: 2022/12/02 17:26:31 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	stop_mlx(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img_1);
	mlx_destroy_image(mlx->mlx, mlx->img_2);
	mlx_destroy_window(mlx->mlx, mlx->window);
	free(mlx->pallets->pallet);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_down_event(int key_code, void *param)
{
	t_data	*mlx;

	mlx = (t_data *)param;
	// printf("key %d\n", key_code);
	if (key_code == 53)
	{
		stop_mlx(mlx);
	}
	arrow_key_events(key_code, mlx);
	arrow_letter_events(key_code, mlx);
	pallet_events(key_code, mlx);
	key_events(key_code, mlx);
	return (0);
}

int	key_up_event(int key_code, void *param)
{
	t_data	*mlx;

	mlx = (t_data *)param;
	if (mlx->key_pressed == 1)
		mlx->key_pressed = 0;
	return (0);
}

int	mouse_event(int button, int x, int y, void *param)
{
	t_data				*mlx;
	// static int			zoom;
	t_complex_number	temp_pos;
	t_complex_number	mids;
	double				f_scale;
	double				factorin = 0.5;
	double				factorout = 0.3;
	double				zoom = 1.5;

	mlx = (t_data *)param;
	mids = create_complex_number(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	// f_scale = (INITIAL_SCALE + mlx->scale);
	f_scale = (mlx->scale);
	// temp_pos = get_mouse_offset_from_center(create_complex_number(x, y));
	temp_pos = create_complex_number(x, y);
	// if (!zoom)
	// 	zoom = 30;

	if (button == 5)
	{
		if (mlx->scale == 0)
			mlx->scale = 1;
		else
			mlx->scale *= zoom;

		mlx->center_offset.x += f_scale * (temp_pos.x - mids.x) / (mids.x) * factorin;
		mlx->center_offset.y += f_scale * (temp_pos.y - mids.y) / (mids.y) * factorin;
		print_complex(mlx->center_offset);
		switch_mlx_image(mlx);
	}
	else if (button == 4)
	{
		mlx->center_offset.x -= f_scale * (temp_pos.x - mids.x) / (mids.x) * factorout;
		mlx->center_offset.y -= f_scale * (temp_pos.y - mids.y) / (mids.y) * factorout;
		if (INITIAL_SCALE + mlx->scale > 1)
			mlx->scale /= zoom;
		print_complex(mlx->center_offset);
		switch_mlx_image(mlx);
	}
	if (button == 5 || button == 4)
	{
		printf("Scale %f", mlx->scale);
		printf("Mouse offset ");
		print_complex(get_mouse_offset_from_center(create_complex_number(x, y)));
		printf("\n");
		// if (mlx->mouse_lock == )
		// {
			// temp_pos = mlx->center_offset;
			// temp_mouse = get_mouse_offset_from_center(create_complex_number(x, y));
			// mlx->center_offset = create_complex_number(temp_mouse.x - temp_pos.x, temp_mouse.y - temp_pos.y);
			
		// }
	}
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

int	loop_hook_events(void *param)
{
	t_data	*mlx;

	mlx = (t_data *)param;
	if (mlx->key_pressed == 1)
	{
		switch_mlx_image(mlx);
	}
	return (0);
}
