/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circles_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:20:57 by mgama             #+#    #+#             */
/*   Updated: 2023/01/12 16:35:08 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

t_circle	create_circle(double r, t_complex_number center)
{
	t_circle	circle;

	circle.center = center;
	circle.r = r;
	circle.b = 1 / r;
	circle.bc = complex_mul(center, create_complex_number(circle.b, 0));
	return (circle);
}

t_circle	*symmetric_set(double x, double y, double radius)
{
	t_circle	*fni;
	t_circle	c1;
	t_circle	c2;
	t_circle	c3;
	double		c3r;

	fni = malloc(3 * sizeof(t_circle));
	if (!fni)
		return (0);
	c1 = create_circle(-radius, create_complex_number(x, y));
	c2 = create_circle(radius / 2,
			create_complex_number(x - (radius / 2), y));
	c3r = fabs(c1.r) - c2.r;
	c3 = create_circle(c3r,
			create_complex_number(c2.center.x + c2.r + c3r,
				c2.center.y));
	fni[0] = c1;
	fni[1] = c2;
	fni[2] = c3;
	return (fni);
}

t_circle	*a_symmetric_set(double x, double y, double radius)
{
	t_circle	*fni;
	t_circle	c1;
	t_circle	c2;
	t_circle	c3;
	double		c3r;

	fni = malloc(3 * sizeof(t_circle));
	if (!fni)
		return (0);
	c1 = create_circle(-radius, create_complex_number(x, y));
	c2 = create_circle(radius / 1.25,
			create_complex_number(x - radius + (radius / 1.25), y));
	c3r = fabs(c1.r) - c2.r;
	c3 = create_circle(c3r,
			create_complex_number(c2.center.x + c2.r + c3r,
				c2.center.y));
	fni[0] = c1;
	fni[1] = c2;
	fni[2] = c3;
	return (fni);
}

t_complex_number	solve_equation(t_complex_number a, t_complex_number b,
	t_complex_number c)
{
	t_complex_number	s;
	t_complex_number	k1;
	t_complex_number	k2;
	t_complex_number	k3;
	t_complex_number	ks;

	s = complex_add(a, complex_add(b, c));
	k1 = complex_mul(a, b);
	k2 = complex_mul(a, c);
	k3 = complex_mul(b, c);
	ks = complex_add(k1, complex_add(k2, k3));
	return (complex_add(complex_mul(complex_sqrt(ks),
				create_complex_number(2, 0)), s));
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
