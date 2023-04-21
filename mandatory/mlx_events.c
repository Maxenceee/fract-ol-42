/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:13:26 by mgama             #+#    #+#             */
/*   Updated: 2023/04/22 01:31:40 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	stop_mlx(t_data *mlx)
{
	if (mlx->img != NULL)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->pallets->pallet != NULL)
		free(mlx->pallets->pallet);
	if (mlx->fractal_list != NULL)
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
	if (key_code == 31)
	{
		ft_printf("\n\033[1;35mCurrent fractal: \033[4m%s%s\n",
			mlx->fractal_list[mlx->current_fractal_type].fractal_name,
			"\033[0m");
		if (mlx->fractal_list[mlx->current_fractal_type].has_formula)
			ft_printf("\033[1;35mCurrent formula: %+.3f %+.3fi %s\n",
				mlx->formula.x, mlx->formula.y, "\033[0m");
		if (mlx->fractal_list[mlx->current_fractal_type].formula_exp != -1)
			ft_printf("\033[1;35mCurrent exponent: %d %s\n",
				mlx->fractal_list[mlx->current_fractal_type].formula_exp,
				"\033[0m");
	}
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
