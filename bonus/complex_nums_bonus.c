/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_nums_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:46:28 by mgama             #+#    #+#             */
/*   Updated: 2026/02/06 00:49:04 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

inline t_complex_number	create_complex_number(double x, double y)
{
	return ((t_complex_number){.x = x, .y = y});
}

inline double	modulus_complex_2(t_complex_number a)
{
	return (a.x * a.x + a.y * a.y);
}

inline double	complex_abs(t_complex_number a)
{
	return (complex_hypot(a.x, a.y));
}

inline double	complex_hypot(double x, double y)
{
	return (sqrt(x * x + y * y));
}

inline t_complex_number	complex_rational_pow(t_complex_number a, unsigned int b)
{
	t_complex_number	n;

	if (b == 0)
		return (create_complex_number(1, 0));
	n = create_complex_number(1, 0);
	while (b > 0)
	{
		if (b & 1)
			n = complex_mul(n, a);
		a = complex_mul(a, a);
		b >>= 1;
	}
	return (n);
}
