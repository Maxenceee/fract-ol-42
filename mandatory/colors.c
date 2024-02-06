/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:03:31 by mgama             #+#    #+#             */
/*   Updated: 2024/02/06 18:21:53 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline int	mix(int from, int to, float mix)
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

inline int	get_color(float iterations, int *pallet, int colors_nb)
{
	float	value;
	float	min_value;
	float	max_value;
	int		i;

	value = iterations / MAX_ITER;
	if (iterations == MAX_ITER)
		return (0x000000);
	i = -1;
	while (++i < (int)(colors_nb - 1))
	{
		min_value = (float)i / colors_nb;
		max_value = (float)(i + 1) / colors_nb;
		if (value >= min_value && value <= max_value)
			return (mix(pallet[i], pallet[i + 1],
					(value - min_value) * colors_nb));
	}
	return (0x000000);
}

inline int	color(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	init_pallets(t_data *mlx)
{
	int			nb;
	t_color		*color_data;

	nb = 11;
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
