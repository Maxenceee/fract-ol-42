/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:12:24 by mgama             #+#    #+#             */
/*   Updated: 2023/05/20 22:19:50 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	*dst;

	dst = (int *)data->addr;
	dst[y * (data->line_length >> 2) + x] = color;
}

void	mlx_update_image(t_data *mlx)
{
	(*mlx->fractal_list[mlx
			->current_fractal_type].fractol_function_nothp)(
				mlx,
				mlx->screen_dims);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
}

void	*render_thread(void *param)
{
	t_thread	*t;
	int			x;
	int			y;

	t = (t_thread *)param;
	y = t->mlx->screen_dims.height / THREADS * t->id;
	while (y < t->mlx->screen_dims.height / THREADS * (t->id + 1))
	{
		x = 0;
		while (x < t->mlx->screen_dims.width)
		{
			(*t->mlx->fractal_list[t->mlx
					->current_fractal_type].fractol_function)(
					t->mlx,
					t->mlx->screen_dims, x, y);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	mlx_update_image_multitp(t_data *mlx)
{
	int			i;
	t_render	*r;

	if (NULL == mlx->fractal_list[mlx
			->current_fractal_type].fractol_function || mlx->no_multithp)
	{
		mlx_update_image(mlx);
		return ;
	}
	handle_exp_variants(mlx);
	i = 0;
	r = &mlx->render;
	while (i < THREADS)
	{
		r->args[i].id = i;
		r->args[i].mlx = mlx;
		if (pthread_create(r->threads + i, NULL,
				render_thread, &(r->args[i])) != 0)
			ft_printf("could not create pthread %d\n", i);
		i++;
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(r->threads[i], NULL);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
}

t_complex_number	aspect_scale(t_data *mlx, t_complex_number mouse_pos,
	t_complex_number mids, double scale)
{
	return (create_complex_number(
			(mouse_pos.x - mids.x) * scale + mlx->center_offset.x,
			(mouse_pos.y - mids.y) * scale + mlx->center_offset.y
		));
}
