/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_home_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:11:42 by mgama             #+#    #+#             */
/*   Updated: 2023/04/21 23:25:08 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

static void	get_coords(t_screen_dim *temp_s, int j,
	t_complex_number dims)
{
	temp_s->top = (dims.y * 0.5) * (j % 2);
	temp_s->left = dims.x * 0.5 * (j - j % 2);
	temp_s->height = (dims.y * 0.5);
	temp_s->center_x = temp_s->left + (temp_s->width * 0.5);
	temp_s->center_y = temp_s->top + (temp_s->height * 0.5);
}

void	parse_screen_dims(t_screen_dim *screens, t_complex_number dims,
	int parts, t_data *mlx)
{
	int				i;
	int				j;
	t_screen_dim	temp_s;
	int				d;

	i = -1;
	d = ((int)dims.x - ((int)dims.x % (parts / 2))) / (parts / 2);
	while (++i < mlx->fractal_count)
	{
		j = i;
		if (mlx->fractal_count % 2 == 1 && i > 1)
			j = i + 1;
		temp_s.width = d;
		if (mlx->fractal_count % 2 == 1 && i == 0)
			temp_s.width = d * 2;
		if (i > mlx->fractal_count - 3)
			temp_s.width += ((int)dims.x % (parts / 2));
		get_coords(&temp_s, j, create_complex_number(d, (int)dims.y));
		screens[i] = temp_s;
	}
	draw_screen_image(screens, mlx);
}

void	draw_screen_image(t_screen_dim *screens, t_data *mlx)
{
	int				i;
	t_screen_dim	s;

	s = mlx->screen_dims;
	i = -1;
	while (++i < mlx->fractal_count)
	{
		mlx->current_fractal_type = i;
		mlx->scale = HOME_SCALE;
		if (mlx->fractal_list[i].has_formula)
			mlx->formula = mlx->fractal_list[i].formula;
		if (!mlx->fractal_list[i].no_pallet)
			mlx->pallet_type = mlx->fractal_list[i].home_pallet;
		mlx->fractal_list[i].home_dims = screens[i];
		mlx->screen_dims = screens[i];
		mlx_update_image_multitp(mlx);
	}
	mlx->screen_dims = s;
	free(screens);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
}

int	show_home(t_data *mlx)
{
	int				segments;
	t_screen_dim	*screens;

	mlx->is_home = 1;
	mlx->mouse_lock = 1;
	mlx->center_offset = create_complex_number(0, 0);
	segments = mlx->fractal_count;
	if (segments % 2 > 0)
		segments++;
	screens = malloc(segments * sizeof(t_screen_dim));
	if (!screens)
	{
		perror("Cannot parse screen");
		exit(EXIT_FAILURE);
	}
	parse_screen_dims(screens, create_complex_number(
			WINDOW_WIDTH, WINDOW_HEIGHT), segments, mlx);
	return (0);
}
