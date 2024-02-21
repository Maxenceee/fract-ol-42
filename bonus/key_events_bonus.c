/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:43:58 by mgama             #+#    #+#             */
/*   Updated: 2024/02/21 19:43:31 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	arrow_key_events(int key_code, t_data *mlx)
{
	t_complex_number	factor;

	factor = create_complex_number(INITIAL_SCALE * 0.5 / mlx->scale,
			INITIAL_SCALE * 0.5 / mlx->scale);
	if (key_code == KEY_LEFT)
	{
		mlx->center_offset.x -= factor.x;
		mlx->key_pressed = 1;
	}
	if (key_code == KEY_RIGHT)
	{
		mlx->center_offset.x += factor.x;
		mlx->key_pressed = 1;
	}
	if (key_code == KEY_DOWN)
	{
		mlx->center_offset.y += factor.y;
		mlx->key_pressed = 1;
	}
	if (key_code == KEY_UP)
	{
		mlx->center_offset.y -= factor.y;
		mlx->key_pressed = 1;
	}
}

void	pallet_events(int key_code, t_data *mlx)
{
	if (key_code == KEY_P)
	{
		if (!mlx->fractal_list[mlx->curr_fractal_type].no_pallet)
		{
			if (mlx->pallet_type == mlx->pallet_nb - 1)
				mlx->pallet_type = 0;
			else
				mlx->pallet_type++;
			mlx->fractal_list[mlx
				->curr_fractal_type].home_pallet = mlx->pallet_type;
		}
		mlx_update_image_multitp(mlx);
	}
}

void	variants_events(int key_code, t_data *mlx)
{
	if (key_code == KEY_V && mlx->fractal_list[mlx
			->curr_fractal_type].has_variants)
	{
		mlx->next_variant = 1;
		mlx_update_image_multitp(mlx);
		mlx->next_variant = 0;
	}
	if (key_code == KEY_B && mlx->fractal_list[mlx
			->curr_fractal_type].has_variants)
	{
		mlx->prev_variant = 1;
		mlx_update_image_multitp(mlx);
		mlx->prev_variant = 0;
	}
}

void	key_events(int key_code, t_data *mlx)
{
	if (key_code == KEY_L)
	{
		mlx->saved_formula = mlx->formula;
		mlx->mouse_lock = !mlx->mouse_lock;
		if (mlx->mouse_lock == 0)
			mlx->need_save = 1;
	}
	if (key_code == KEY_SPACE)
	{
		mlx->scale = INITIAL_SCALE;
		mlx->center_offset = create_complex_number(0, 0);
		mlx_update_image_multitp(mlx);
	}
	if (key_code == KEY_I)
		mlx->mouse_offset = !mlx->mouse_offset;
	if (key_code == KEY_T)
		switch_fractal(mlx);
	if (key_code == KEY_H)
		show_home(mlx);
}
