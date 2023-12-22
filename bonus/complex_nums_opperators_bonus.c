/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_nums_opperators_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:11:20 by mgama             #+#    #+#             */
/*   Updated: 2023/12/22 11:31:30 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_complex_number	complex_add(t_complex_number a, t_complex_number b)
{
	return (create_complex_number(a.x + b.x, a.y + b.y));
}

t_complex_number	complex_sub(t_complex_number a, t_complex_number b)
{
	return (create_complex_number(a.x - b.x, a.y - b.y));
}

t_complex_number	complex_mul(t_complex_number a, t_complex_number b)
{
	if (b.y == 0 && a.y == 0)
		return (create_complex_number(a.x * b.x, 0));
	return (create_complex_number(
			a.x * b.x - a.y * b.y,
			a.x * b.y + a.y * b.x));
}

t_complex_number	complex_div(t_complex_number a, t_complex_number b)
{
	double	x;
	double	t;

	if (a.x == 0 && a.y == 0)
		return (create_complex_number(0, 0));
	if (0 == b.y)
		return (create_complex_number(a.x / b.x, a.y / b.x));
	if (fabs(b.x) < fabs(b.y))
	{
		x = b.x / b.y;
		t = b.x * x + b.y;
		return (create_complex_number(
				(a.x * x + a.y) / t,
				(a.y * x - a.x) / t));
	}
	else
	{
		x = b.y / b.x;
		t = b.y * x + b.x;
		return (create_complex_number(
				(a.x + a.y * x) / t,
				(a.y - a.x * x) / t));
	}
}

t_complex_number	complex_sqrt(t_complex_number cmpl)
{
	double	a;
	double	b;
	double	r;
	double	re;
	double	im;

	a = cmpl.x;
	b = cmpl.y;
	r = complex_abs(cmpl);
	if (a >= 0)
	{
		if (b == 0)
			return (create_complex_number(sqrtf(a), 0));
		re = 0.5 * sqrtf(2.0 * (r + a));
	}
	else
		re = fabs(b) / sqrtf(2 * (r - a));
	if (a <= 0)
		im = 0.5 * sqrtf(2.0 * (r - a));
	else
		re = fabs(b) / sqrtf(2 * (r + a));
	if (b < 0)
		im = -im;
	return (create_complex_number(re, im));
}
