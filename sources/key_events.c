/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:43:58 by mgama             #+#    #+#             */
/*   Updated: 2022/12/15 14:01:26 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
		if (mlx->no_pallet)
		{
			mlx->fractal_symmetry = !mlx->fractal_symmetry;
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
		switch_mlx_image(mlx);
	}
	if (key_code == 31)
	{
		ft_printf("\n\033[1;35mCurrent state: %+.3f %+.3fi %s\n",
			mlx->formula.x, mlx->formula.y, "\033[0m");
	}
	if (key_code == 34)
		mlx->mouse_offset = !mlx->mouse_offset;
	if (key_code == 17)
	{
		if (mlx->fractal_type + 1 < mlx->fractal_count)
			mlx->fractal_type++;
		else
			mlx->fractal_type = 0;
		fractal_gen(mlx);
	}
}
