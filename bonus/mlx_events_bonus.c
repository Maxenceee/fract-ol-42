/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:13:26 by mgama             #+#    #+#             */
/*   Updated: 2024/02/21 19:56:20 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	print_state(t_data *mlx)
{
	ft_printf("\n\033[1;35mCurrent fractal: \033[4m%s%s\n",
		mlx->fractal_list[mlx->curr_fractal_type].fractal_name,
		"\033[0m");
	if (mlx->fractal_list[mlx->curr_fractal_type].has_formula)
		ft_printf("\033[1;35mCurrent formula: Z^%d %+.3f %+.3fi %s\n",
			mlx->fractal_list[mlx->curr_fractal_type].formula_exp,
			mlx->formula.x, mlx->formula.y, "\033[0m");
	if (mlx->fractal_list[mlx->curr_fractal_type].formula_exp != -1
		&& !mlx->fractal_list[mlx->curr_fractal_type].has_formula)
		ft_printf("\033[1;35mCurrent exponent: %d %s\n",
			mlx->fractal_list[mlx->curr_fractal_type].formula_exp,
			"\033[0m");
}

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
	ft_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_down_event(int key_code, void *param)
{
	t_data	*mlx;

	mlx = (t_data *)param;
	if (key_code == KEY_ESC)
	{
		stop_mlx(mlx);
	}
	if (mlx->is_home)
		return (0);
	arrow_key_events(key_code, mlx);
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
	if (key_code == KEY_O)
		print_state(mlx);
	if (key_code == KEY_S)
	{
		mlx->smooth = !mlx->smooth;
		mlx_update_image_multitp(mlx);
	}
	if (key_code == KEY_M)
	{
		ft_printf("\033[1;34mMulti thread enabled \033[1;31m\033[4m%d\n%s",
			mlx->no_multithp, "\033[0m");
		mlx->no_multithp = !mlx->no_multithp;
		mlx_update_image_multitp(mlx);
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
		mlx_update_image_multitp(mlx);
	return (0);
}
