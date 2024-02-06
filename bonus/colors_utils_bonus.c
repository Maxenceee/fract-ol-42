/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:27:12 by mgama             #+#    #+#             */
/*   Updated: 2024/02/06 19:05:45 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static inline int	ft_lerpi(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

inline int	flinear_color(float iterations, t_color pallet)
{
	float	value;
	float	min_value;
	float	max_value;
	int		i;

	value = iterations / MAX_ITER;
	if (iterations == MAX_ITER)
		return (0x000000);
	i = -1;
	while (++i < (int)pallet.pallet_length)
	{
		min_value = (float)i / pallet.pallet_length;
		max_value = (float)(i + 1) / pallet.pallet_length;
		if (value >= min_value && value <= max_value)
			return (mix(pallet.pallet[i], pallet.pallet[i + 1],
					(value - min_value) * pallet.pallet_length));
	}
	return (0x000000);
}

static inline t_colorf	clerp(t_colorf c1, t_colorf c2, double p)
{
	if (c1.value == c2.value)
		return (c1);
	return ((t_colorf){
		.rgba.r = (char)ft_lerpi((int)c1.rgba.r, (int)c2.rgba.r, p),
		.rgba.g = (char)ft_lerpi((int)c1.rgba.g, (int)c2.rgba.g, p),
		.rgba.b = (char)ft_lerpi((int)c1.rgba.b, (int)c2.rgba.b, p),
		.rgba.a = (char)0x00
	});
}

inline t_colorf	linear_color(double i, int max, t_color p)
{
	double		index;
	double		adjust;
	int			c;

	index = i / max;
	c = p.pallet_length - 1;
	adjust = fmod(index, 1.0f / c) * c;
	return (clerp((t_colorf)(p.pallet[(int)(index * c) + 1]),
		(t_colorf)(p.pallet[(int)(index * c)]),
		(int)(adjust + 1) - adjust));
}

inline t_colorf	smooth_color(t_pixel p, int max, t_color pal)
{
	double	i;
	double	zn;
	double	nu;

	zn = log(p.coords.x * p.coords.x + p.coords.y * p.coords.y) / 2.0f;
	nu = log(zn / log(2)) / log(2);
	i = p.i + 1 - nu;
	if (i < 0)
		i = 0;
	return (linear_color(i, max, pal));
}
