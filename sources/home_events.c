/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:10:50 by mgama             #+#    #+#             */
/*   Updated: 2022/12/17 19:07:40 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_home_event(t_data *mlx, int button, int x, int y)
{
	catch_fractal_from_screen(mlx, x, y);
	return (0);
}

void	catch_fractal_from_screen(t_data *mlx, int x, int y)
{
	int				i;
	t_screen_dim	f;

	i = -1;
	while (++i < mlx->fractal_count)
	{
		f = mlx->fractal_list[i].home_dims;
		if (x >= f.left && x <= f.left + f.width
			&& y >= f.top && y <= f.top + f.height)
			break ;
	}
	mlx->scale = INITIAL_SCALE;
	mlx->is_home = 0;
	mlx->current_fractal_type = i;
	mlx->pallet_type = mlx->fractal_list[i].home_pallet;
	on_fractal_gen(mlx);
	mlx_update_image(mlx);
}