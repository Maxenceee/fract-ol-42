/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 23:23:10 by mgama             #+#    #+#             */
/*   Updated: 2026/02/06 00:23:12 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

inline void	put_image_to_window(t_data *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
}

inline void	mlx_update_image(t_data *mlx)
{
	(*mlx->fractal_list[mlx
			->curr_fractal_type].fractol_function_nothp)(
				mlx,
				mlx->screen_dims);
	put_image_to_window(mlx);
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
					->curr_fractal_type].fractol_function)(
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
			->curr_fractal_type].fractol_function || mlx->no_multithp)
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
	put_image_to_window(mlx);
}
