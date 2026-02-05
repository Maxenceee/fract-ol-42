/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_nums_opperators_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:11:20 by mgama             #+#    #+#             */
/*   Updated: 2026/02/06 00:52:15 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

inline t_complex_number	complex_add(t_complex_number a, t_complex_number b)
{
	return (create_complex_number(a.x + b.x, a.y + b.y));
}

inline t_complex_number	complex_sub(t_complex_number a, t_complex_number b)
{
	return (create_complex_number(a.x - b.x, a.y - b.y));
}

inline t_complex_number	complex_mul(t_complex_number a, t_complex_number b)
{
	return (create_complex_number(
			a.x * b.x - a.y * b.y,
			a.x * b.y + a.y * b.x));
}

inline t_complex_number	complex_div(t_complex_number a, t_complex_number b)
{
	double denom;

	denom = b.x * b.x + b.y * b.y;
	return (create_complex_number(
			(a.x * b.x + a.y * b.y) / denom,
			(a.y * b.x - a.x * b.y) / denom
		));
}

inline t_complex_number	complex_sqrt(t_complex_number cmpl)
{
	double	r;
	double	re;
	double	im;

	r = sqrt(cmpl.x * cmpl.x + cmpl.y * cmpl.y);
	re = sqrt((r + cmpl.x) / 2.0);
	im = sqrt((r - cmpl.x) / 2.0);
	if (cmpl.y < 0)
		im = -im;
	return (create_complex_number(re, im));
}
