/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pallets2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:01:33 by mgama             #+#    #+#             */
/*   Updated: 2022/11/29 21:02:58 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	pallet_6(t_color *color_data, int idx)
{
	int			*colors;
	t_color		temp_color_data;

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
	color_data[idx] = temp_color_data;
}

void	pallet_7(t_color *color_data, int idx)
{
	int			*colors;
	t_color		temp_color_data;

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
	color_data[idx] = temp_color_data;
}
