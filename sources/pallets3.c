/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pallets3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:14:25 by mgama             #+#    #+#             */
/*   Updated: 2022/12/20 19:14:41 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
