/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_nums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:46:28 by mgama             #+#    #+#             */
/*   Updated: 2022/12/17 00:48:05 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex_number	create_complex_number(double x, double y)
{
	t_complex_number	num;

	num.x = x;
	num.y = y;
	return (num);
}

double	modulus_complex_2(t_complex_number a)
{
	return (a.x * a.x + a.y * a.y);
}

double	complex_abs(t_complex_number a)
{
	return (complex_hypot(a.x, a.y));
}

double	complex_hypot(double x, double y)
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

t_complex_number	complex_rational_pow(t_complex_number a, unsigned int b)
{
	unsigned int		i;
	t_complex_number	n;

	i = -1;
	while (++i < b)
	{
		n = complex_mul(n, a);
	}
	return (n);
}
