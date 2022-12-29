/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:13:26 by mgama             #+#    #+#             */
/*   Updated: 2022/12/29 23:37:10 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	stop_mlx(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->window);
	free(mlx->pallets->pallet);
	free(mlx->fractal_list);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_down_event(int key_code, void *param)
{
	t_data	*mlx;

	mlx = (t_data *)param;
	if (key_code == 53)
	{
		stop_mlx(mlx);
	}
	if (mlx->is_home)
		return (0);
	arrow_key_events(key_code, mlx);
	arrow_letter_events(key_code, mlx);
	return (0);
}

int	key_up_event(int key_code, void *param)
{
	t_data	*mlx;

	mlx = (t_data *)param;
	if (mlx->is_home)
		return (0);
	if (mlx->key_pressed == 1)
		mlx->key_pressed = 0;
	pallet_events(key_code, mlx);
	variants_events(key_code, mlx);
	key_events(key_code, mlx);
	return (0);
}

int	loop_hook_events(void *param)
{
	t_data	*mlx;

	mlx = (t_data *)param;
	if (mlx->is_home)
		return (0);
	if (mlx->key_pressed == 1)
		mlx_update_image(mlx);
	return (0);
}
