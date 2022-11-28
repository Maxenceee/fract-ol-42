/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:13:26 by mgama             #+#    #+#             */
/*   Updated: 2022/11/28 17:26:18 by mgama            ###   ########.fr       */
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
	t_data *mlx;
	double	offset;

	mlx = (t_data *)param;

	offset = COMPLEX_NUMBER_OFFSET;
	// printf("key %d\n", key_code);
	if (key_code == 53)
	{
		stop_mlx(mlx);
	}
	if (key_code == 123)
	{
		/* left */
		// mlx->center_offset.x += 50;
		mlx->center_offset.x -= 50;
		mlx->key_pressed = 1;
	}
	if (key_code == 124)
	{
		/* right */
		// mlx->center_offset.x -= 50;
		mlx->center_offset.x += 50;
		mlx->key_pressed = 1;
	}
	if (key_code == 125)
	{
		/* bottom */
		// mlx->center_offset.y -= 50;
		mlx->center_offset.y += 50;
		mlx->key_pressed = 1;
	}
	if (key_code == 126)
	{
		/* top */
		// mlx->center_offset.y += 50;
		mlx->center_offset.y -= 50;
		mlx->key_pressed = 1;
	}
	if (key_code == 13)
	{
		/* z; r++ */
		mlx->formula.x += offset;
		mlx->key_pressed = 1;
	}
	if (key_code == 1)
	{
		/* s; r-- */
		mlx->formula.x -= offset;
		mlx->key_pressed = 1;
	}
	if (key_code == 0)
	{
		/* q; i-- */
		mlx->formula.y -= offset;
		mlx->key_pressed = 1;
	}
	if (key_code == 2)
	{
		/* d; i++ */
		mlx->formula.y += offset;
		mlx->key_pressed = 1;
	}
	if (key_code == 35)
	{
		if (mlx->no_pallet)
		{
			mlx->pallet_type = !mlx->pallet_type;
		}
		else
		{
			if (mlx->pallet_type == mlx->pallet_nb - 1)
				mlx->pallet_type = 0;
			else
				mlx->pallet_type++;
		}
		switch_mlx_image(mlx);
	}
	return (0);
}

int	key_up_event(int key_code, void *param)
{
	t_data *mlx;

	mlx = (t_data *)param;
	if (mlx->key_pressed == 1)
		mlx->key_pressed = 0;
	return (0);
}

int mouse_event(int button, int x, int y, void *param)
{
	t_data *mlx;
	static int	zoom;

	mlx = (t_data *)param;
	if (!zoom)
		zoom = 30;

	if (button == 5)
		mlx->scale += zoom;
	else if (button == 4)
	{
		if (INITIAL_SCALE + mlx->scale > 0 )
			mlx->scale -= zoom;
	}
	if (button == 5 || button == 4)
		// printf("Mouse offset ");
		// print_complex(get_mouse_offset_from_center(create_complex_number(x, y)));
		// printf("\n");
		// mlx->mouse_offset = get_mouse_offset_from_center(create_complex_number(x, y));
		switch_mlx_image(mlx);
	return (0);
}

int	loop_hook_events(void *param)
{
	t_data *mlx;

	mlx = (t_data *)param;
	if (mlx->key_pressed == 1)
	{
		switch_mlx_image(mlx);
	}
	return (0);
}