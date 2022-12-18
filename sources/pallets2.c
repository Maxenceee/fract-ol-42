/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pallets2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:01:33 by mgama             #+#    #+#             */
/*   Updated: 2022/12/18 17:50:44 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	pallet_6(t_color *color_data, int idx)
{
	int			*colors;
	t_color		temp_color_data;
	int			n;

	n = 6;
	colors = malloc(n * sizeof(int));
	if (!colors)
		pallet_error(colors, color_data);
	colors[0] = 0x25153b;
	colors[1] = 0xff0000;
	colors[2] = 0x06f9db;
	colors[3] = 0xf774ba;
	colors[4] = 0xa600f5;
	colors[5] = 0xff8200;
	temp_color_data.pallet = colors;
	temp_color_data.pallet_length = n;
	color_data[idx] = temp_color_data;
}

void	pallet_7(t_color *color_data, int idx)
{
	int			*colors;
	t_color		temp_color_data;
	int			n;

	n = 5;
	colors = malloc(n * sizeof(int));
	if (!colors)
		pallet_error(colors, color_data);
	colors[0] = 0x215d17;
	colors[1] = 0xd9ff00;
	colors[2] = 0x86f4f0;
	colors[3] = 0xff0047;
	colors[4] = 0xfdff6a;
	temp_color_data.pallet = colors;
	temp_color_data.pallet_length = n;
	color_data[idx] = temp_color_data;
}

void	pallet_8(t_color *color_data, int idx)
{
	int			*colors;
	t_color		temp_color_data;
	int			n;

	n = 2;
	colors = malloc(n * sizeof(int));
	if (!colors)
		pallet_error(colors, color_data);
	colors[0] = 0x000000;
	colors[1] = 0xffffff;
	temp_color_data.pallet = colors;
	temp_color_data.pallet_length = n;
	color_data[idx] = temp_color_data;
}

void	pallet_9(t_color *color_data, int idx)
{
	int			*colors;
	t_color		temp_color_data;
	int			n;

	n = 2;
	colors = malloc(n * sizeof(int));
	if (!colors)
		pallet_error(colors, color_data);
	colors[0] = 0xffffff;
	colors[1] = 0x000000;
	temp_color_data.pallet = colors;
	temp_color_data.pallet_length = n;
	color_data[idx] = temp_color_data;
}

void	pallet_10(t_color *color_data, int idx)
{
	int			*colors;
	t_color		temp_color_data;
	int			n;

	n = 2;
	colors = malloc(n * sizeof(int));
	if (!colors)
		pallet_error(colors, color_data);
	colors[0] = 0x0B1F39;
	colors[1] = 0xf78166;
	temp_color_data.pallet = colors;
	temp_color_data.pallet_length = n;
	color_data[idx] = temp_color_data;
}

void	pallet_11(t_color *color_data, int idx)
{
	int			*colors;
	t_color		temp_color_data;
	int			n;

	n = 3;
	colors = malloc(n * sizeof(int));
	if (!colors)
		pallet_error(colors, color_data);
	colors[0] = 0xCEF3FC;
	colors[1] = 0x2D3E2B;
	colors[2] = 0xFCCEF2;
	temp_color_data.pallet = colors;
	temp_color_data.pallet_length = n;
	color_data[idx] = temp_color_data;
}
