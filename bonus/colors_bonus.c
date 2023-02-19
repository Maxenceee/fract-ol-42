/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:03:31 by mgama             #+#    #+#             */
/*   Updated: 2023/02/19 02:03:55 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	get_color(t_data *mlx, t_pixel pix, t_color pallet)
{
	if (pix.i >= MAX_ITER)
		return (0x000000);
	if (mlx->smooth)
		return (smooth_color(pix, MAX_ITER, pallet).value);
	return (flinear_color(pix.i, pallet));
}

void	init_pallets(t_data *mlx)
{
	int			nb;
	t_color		*color_data;

	nb = 12;
	color_data = malloc(nb * sizeof(t_color));
	if (!color_data)
		pallet_error(NULL, color_data);
	pallet_1(color_data, 0);
	pallet_2(color_data, 1);
	pallet_3(color_data, 2);
	pallet_4(color_data, 3);
	pallet_5(color_data, 4);
	pallet_6(color_data, 5);
	pallet_7(color_data, 6);
	pallet_8(color_data, 7);
	pallet_9(color_data, 8);
	pallet_10(color_data, 9);
	pallet_11(color_data, 10);
	pallet_12(color_data, 11);
	mlx->pallets = color_data;
	mlx->pallet_nb = nb;
}

void	pallet_error(int *colors, t_color *color_data)
{
	if (colors != NULL)
		free(colors);
	free(color_data);
	perror("Cannot generate color pallets");
	exit(EXIT_FAILURE);
}

int	mix(int from, int to, float mix)
{
	float	r;
	float	g;
	float	b;

	r = (float)(from >> 16)*(1. - mix) + (float)(to >> 16)*mix;
	g = (float)((from >> 8) & 255)*(1. - mix)
		+ (float)((to >> 8) & 255)*mix;
	b = (float)(from & 255)*(1. - mix) + (float)(to & 255)*mix;
	return (color((int)r, (int)g, (int)b));
}

int	color(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
