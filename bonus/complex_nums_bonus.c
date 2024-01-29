/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_nums_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:46:28 by mgama             #+#    #+#             */
/*   Updated: 2024/01/29 16:00:31 by mgama            ###   ########.fr       */
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
	double	a;
	double	b;

	a = fabs(x);
	b = fabs(y);
	if (a < 3000 && b < 3000)
		return (sqrtf(a * a + b * b));
	if (a < b)
	{
		a = b;
		b = x / y;
	}
	else
		b = x / y;
	return (a * sqrtf(1 + b * b));
}

inline t_complex_number	complex_rational_pow(t_complex_number a, unsigned int b)
{
	unsigned int		i;
	t_complex_number	n;

	if (b == 0)
		return (create_complex_number(0, 0));
	i = -1;
	n = a;
	while (++i < b - 1)
	{
		n = complex_mul(n, a);
	}
	return (n);
}
