/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_home.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:11:42 by mgama             #+#    #+#             */
/*   Updated: 2023/05/02 01:52:16 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	parse_screen_dims(int width, int height, int parts, t_data *mlx)
{
	t_screen_dim	*screens;
	int				i;
	t_screen_dim	temp_s;

	screens = malloc(parts * sizeof(t_screen_dim));
	if (!screens)
		return (0);
	i = -1;
	while (++i < parts)
	{
		temp_s.top = (height >> 1) * (i % 2);
		temp_s.left = (width / (parts >> 1)) / 2 * (i - i % 2);
		temp_s.width = (width / (parts >> 1));
		temp_s.height = (height >> 1);
		temp_s.center_x = temp_s.left + (temp_s.width >> 1);
		temp_s.center_y = temp_s.top + (temp_s.height >> 1);
		screens[i] = temp_s;
	}
	draw_screen_image(screens, parts, mlx);
	return (1);
}

void	draw_screen_image(t_screen_dim *screens, int screens_count, t_data *mlx)
{
	int	i;

	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	i = -1;
	while (++i < screens_count)
	{
		mlx->current_fractal_type = i;
		mlx->scale = mlx->fractal_list[i].home_scale;
		if (mlx->fractal_list[i].has_formula)
			mlx->formula = mlx->fractal_list[i].formula;
		if (!mlx->fractal_list[i].no_pallet)
			mlx->pallet_type = mlx->fractal_list[i].home_pallet;
		mlx->fractal_list[i].home_dims = screens[i];
		(*mlx->fractal_list[i].fractol_function)(mlx, screens[i]);
	}
	free(screens);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
}

int	show_home(t_data *mlx)
{
	int				segments;

	mlx->is_home = 1;
	mlx->mouse_lock = 1;
	mlx->center_offset = create_complex_number(0, 0);
	segments = mlx->fractal_count;
	if (segments % 2 > 0)
		segments++;
	if (!parse_screen_dims(WINDOW_WIDTH, WINDOW_HEIGHT, segments, mlx))
	{
		perror("Cannot parse screen");
		exit(EXIT_FAILURE);
	}
	return (0);
}
