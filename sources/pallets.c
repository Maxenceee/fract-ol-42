/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pallets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:55:18 by mgama             #+#    #+#             */
/*   Updated: 2022/12/15 20:19:07 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	pallet_1(t_color *color_data, int idx)
{
	int			*colors;
	t_color		temp_color_data;

	colors = malloc(5 * sizeof(int));
	if (!colors)
		pallet_error(colors, color_data);
	colors[0] = color(0, 7, 100);
	colors[1] = color(32, 107, 203);
	colors[2] = color(237, 255, 255);
	colors[3] = color(255, 170, 0);
	colors[4] = color(0, 2, 0);
	temp_color_data.pallet = colors;
	temp_color_data.pallet_length = 5;
	color_data[idx] = temp_color_data;
}

void	pallet_2(t_color *color_data, int idx)
{
	int			*colors;
	t_color		temp_color_data;

	colors = malloc(5 * sizeof(int));
	if (!colors)
		pallet_error(colors, color_data);
	colors[0] = color(44, 62, 80);
	colors[1] = color(231, 76, 60);
	colors[2] = color(236, 240, 241);
	colors[3] = color(52, 152, 219);
	colors[4] = color(41, 128, 85);
	temp_color_data.pallet = colors;
	temp_color_data.pallet_length = 5;
	color_data[idx] = temp_color_data;
}

void	pallet_3(t_color *color_data, int idx)
{
	int			*colors;
	t_color		temp_color_data;

	colors = malloc(6 * sizeof(int));
	if (!colors)
		pallet_error(colors, color_data);
	colors[0] = color(96, 125, 139);
	colors[1] = color(1, 40, 64);
	colors[2] = color(69, 0, 3);
	colors[3] = color(92, 20, 140);
	colors[4] = color(255, 220, 0);
	colors[5] = color(150, 202, 45);
	temp_color_data.pallet = colors;
	temp_color_data.pallet_length = 6;
	color_data[idx] = temp_color_data;
}

void	pallet_4(t_color *color_data, int idx)
{
	int			*colors;
	t_color		temp_color_data;

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
	color_data[idx] = temp_color_data;
}

void	pallet_5(t_color *color_data, int idx)
{
	int			*colors;
	t_color		temp_color_data;

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
	color_data[idx] = temp_color_data;
}
