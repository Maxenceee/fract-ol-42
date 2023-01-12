/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:43:58 by mgama             #+#    #+#             */
/*   Updated: 2023/01/12 16:36:07 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	arrow_key_events(int key_code, t_data *mlx)
{
	t_complex_number	factor;

	factor = create_complex_number(INITIAL_SCALE / mlx->scale,
			INITIAL_SCALE / mlx->scale);
	if (key_code == 123)
	{
		mlx->center_offset.x -= factor.x;
		mlx->key_pressed = 1;
	}
	if (key_code == 124)
	{
		mlx->center_offset.x += factor.x;
		mlx->key_pressed = 1;
	}
	if (key_code == 125)
	{
		mlx->center_offset.y += factor.y;
		mlx->key_pressed = 1;
	}
	if (key_code == 126)
	{
		mlx->center_offset.y -= factor.y;
		mlx->key_pressed = 1;
	}
}

void	arrow_letter_events(int key_code, t_data *mlx)
{
	double	offset;

	offset = COMPLEX_NUMBER_OFFSET;
	if (key_code == 13)
	{
		mlx->formula.x += offset;
		mlx->key_pressed = 1;
	}
	if (key_code == 1)
	{
		mlx->formula.x -= offset;
		mlx->key_pressed = 1;
	}
	if (key_code == 0)
	{
		mlx->formula.y -= offset;
		mlx->key_pressed = 1;
	}
	if (key_code == 2)
	{
		mlx->formula.y += offset;
		mlx->key_pressed = 1;
	}
}

void	pallet_events(int key_code, t_data *mlx)
{
	if (key_code == 35)
	{
		if (!mlx->fractal_list[mlx->current_fractal_type].no_pallet)
		{
			if (mlx->pallet_type == mlx->pallet_nb - 1)
				mlx->pallet_type = 0;
			else
				mlx->pallet_type++;
			mlx->fractal_list[mlx
				->current_fractal_type].home_pallet = mlx->pallet_type;
		}
		mlx_update_image(mlx);
	}
}

void	variants_events(int key_code, t_data *mlx)
{
	if (key_code == 9 && mlx->fractal_list[mlx
			->current_fractal_type].has_variants)
	{
		mlx->next_variant = 1;
		mlx_update_image(mlx);
		mlx->next_variant = 0;
	}
	if (key_code == 11 && mlx->fractal_list[mlx
			->current_fractal_type].has_variants)
	{
		mlx->prev_variant = 1;
		mlx_update_image(mlx);
		mlx->prev_variant = 0;
	}
}

void	key_events(int key_code, t_data *mlx)
{
	if (key_code == 37)
	{
		mlx->saved_formula = mlx->formula;
		mlx->mouse_lock = !mlx->mouse_lock;
		if (mlx->mouse_lock == 0)
			mlx->need_save = 1;
	}
	if (key_code == 49)
	{
		mlx->scale = INITIAL_SCALE;
		mlx->center_offset = create_complex_number(0, 0);
		mlx_update_image(mlx);
	}
	if (key_code == 34)
		mlx->mouse_offset = !mlx->mouse_offset;
	if (key_code == 17)
		switch_fractal(mlx);
	if (key_code == 4)
		show_home(mlx);
}
