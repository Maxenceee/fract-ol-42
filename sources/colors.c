/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:03:31 by mgama             #+#    #+#             */
/*   Updated: 2022/11/27 23:48:44 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int mix(int from, int to, float mix)
{
	float r = (float)(from >> 16) * (1. - mix) + (float)(to >> 16) * mix;
	float g = (float)((from >> 8) & 255) * (1. - mix) + (float)((to >> 8) & 255) * mix;
	float b = (float)(from & 255) * (1. - mix) + (float)(to & 255) * mix;
	return (Color((int)r, (int)g, (int)b));
}

int get_color(float iterations, int *pallet, int colors_nb)
{
	float	value;
	float	min_value;
	float	max_value;
	int		i;

	value = iterations / MAX_ITER;
	if (iterations == MAX_ITER)
		return (0x000000);
	i = -1;
	while (++i < (int)colors_nb)
	{
		min_value = (float)i / colors_nb;
		max_value = (float)(i + 1) / colors_nb;
		if (value >= min_value && value <= max_value)
			return (mix(pallet[i], pallet[i + 1], (value - min_value) * colors_nb));
	}
	return (0x000000);
}

// int simple_hsl_to_rgb(double hue)
// {
// 	int     ret;
// 	int     i;
	
// 	hue -= (long) hue;
// 	hue = 6.;
// 	i = (int) hue;
// 	ret = 0xffffff;
// 	ret -= 0xff << (i / 2 + 2) % 3 * 8;
// 	ret -= ((int)(fabs(fmod(hue, 2.) - 1.) * 0xff)) << (7 - i) % 3 * 8;
// 	return (ret);
// }

int Color(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void	init_pallets(t_data *mlx)
{
	int			*colors;
	int			nb;
	t_color		*color_data;
	t_color		temp_color_data;

	nb = 7;
	color_data = malloc(nb * sizeof(t_color));
	if (!color_data)
		pallet_error(colors, color_data);
	colors = malloc(5 * sizeof(int));
	if (!colors)
		pallet_error(colors, color_data);
	colors[0] = Color(  0,   7, 100);
	colors[1] = Color( 32, 107, 203);
	colors[2] = Color(237, 255, 255);
	colors[3] = Color(255, 170,   0);
	colors[4] = Color(  0,   2,   0);
	temp_color_data.pallet = colors;
	temp_color_data.pallet_length = 5;
	color_data[0] = temp_color_data;

	colors = malloc(5 * sizeof(int));
	if (!colors)
		pallet_error(colors, color_data);
	colors[0] = Color( 44,  62,  80);
	colors[1] = Color(231,  76,  60);
	colors[2] = Color(236, 240, 241);
	colors[3] = Color( 52, 152, 219);
	colors[4] = Color( 41, 128,  85);
	temp_color_data.pallet = colors;
	temp_color_data.pallet_length = 5;
	color_data[1] = temp_color_data;
	
	colors = malloc(6 * sizeof(int));
	if (!colors)
		pallet_error(colors, color_data);
	colors[0] = Color( 96, 125, 139);
	colors[1] = Color(  1,  40,  64);
	colors[2] = Color( 69,   0,   3);
	colors[3] = Color( 92,  20, 140);
	colors[4] = Color(255, 220,   0);
	colors[5] = Color(150, 202, 45);
	temp_color_data.pallet = colors;
	temp_color_data.pallet_length = 6;
	color_data[2] = temp_color_data;
	
	colors = malloc(5 * sizeof(int));
	if (!colors)
		pallet_error(colors, color_data);
	colors[0] = 0x105057;
	colors[1] = 0x898C8B;
	colors[2] = 0xFF81D0;
	colors[3] = 0x400036;
	colors[4] = 0x919151;
	temp_color_data.pallet = colors;
	temp_color_data.pallet_length = 5;
	color_data[3] = temp_color_data;
	
	colors = malloc(11 * sizeof(int));
	if (!colors)
		pallet_error(colors, color_data);
	colors[0] = 0xff0000;
	colors[1] = 0xff8200;
	colors[2] = 0xfffa00;
	colors[3] = 0x5dff00;
	colors[4] = 0x06f9db;
	colors[5] = 0x057bf2;
	colors[6] = 0x1104f4;
	colors[7] = 0xa600f5;
	colors[8] = 0xf114ee;
	colors[9] = 0xf774ba;
	colors[10] = 0xff0000;
	temp_color_data.pallet = colors;
	temp_color_data.pallet_length = 11;
	color_data[4] = temp_color_data;
	
	colors = malloc(11 * sizeof(int));
	if (!colors)
		pallet_error(colors, color_data);
	colors[0] = 0x25153b;
	colors[1] = 0xff8200;
	colors[2] = 0x06f9db;
	colors[3] = 0xa600f5;
	colors[4] = 0xff0000;
	colors[5] = 0xf774ba;
	colors[6] = 0x1104f4;
	colors[7] = 0xf114ee;
	colors[8] = 0xfffa00;
	colors[9] = 0x057bf2;
	colors[10] = 0x5dff00;
	temp_color_data.pallet = colors;
	temp_color_data.pallet_length = 11;
	color_data[5] = temp_color_data;

	mlx->pallets = color_data;
	mlx->pallet_nb = nb;
	
	colors = malloc(5 * sizeof(int));
	if (!colors)
		pallet_error(colors, color_data);
	colors[0] = 0x215d17;
	colors[1] = 0xd9ff00;
	colors[2] = 0x86f4f0;
	colors[3] = 0xff0047;
	colors[4] = 0xfdff6a;
	temp_color_data.pallet = colors;
	temp_color_data.pallet_length = 5;
	color_data[6] = temp_color_data;

	mlx->pallets = color_data;
	mlx->pallet_nb = nb;
}

void	pallet_error(int *colors, t_color *color_data)
{
	free(colors);
	free(color_data);
	exit(EXIT_FAILURE);
}