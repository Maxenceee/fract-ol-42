/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:03:31 by mgama             #+#    #+#             */
/*   Updated: 2022/12/01 13:12:01 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

int	get_color(float iterations, int *pallet, int colors_nb)
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
			return (mix(pallet[i], pallet[i + 1],
					(value - min_value) * colors_nb));
	}
	return (0x000000);
}

int	color(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
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
	pallet_1(color_data, 0);
	pallet_2(color_data, 1);
	pallet_3(color_data, 2);
	pallet_4(color_data, 3);
	pallet_5(color_data, 4);
	pallet_6(color_data, 5);
	pallet_7(color_data, 6);
	mlx->pallets = color_data;
	mlx->pallet_nb = nb;
}

void	pallet_error(int *colors, t_color *color_data)
{
	free(colors);
	free(color_data);
	exit(EXIT_FAILURE);
}
