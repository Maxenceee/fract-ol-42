/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:12:24 by mgama             #+#    #+#             */
/*   Updated: 2022/12/14 22:00:57 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	switch_mlx_image(t_data *mlx)
{
	static int	img_type;

	if (!img_type)
		img_type = 0;
	if (img_type == 0)
	{
		mlx->curr_img = mlx->img_1;
		img_type = 1;
	}
	else if (img_type == 1)
	{
		mlx->curr_img = mlx->img_2;
		img_type = 0;
	}
	mlx->addr = mlx_get_data_addr(mlx->curr_img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	(*mlx->fractol_function)(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->curr_img, 0, 0);
}

void	init_fractol(void (*f)(t_data*), t_data *mlx)
{
	mlx->fractol_function = *f;
	mlx->scale = INITIAL_SCALE;
	mlx->mouse_offset = 1;
	mlx->key_pressed = 0;
	mlx->pallet_type = 0;
	mlx->center_offset = create_complex_number(0, 0);
	init_pallets(mlx);
	switch_mlx_image(mlx);
}
