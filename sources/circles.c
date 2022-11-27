/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:20:57 by mgama             #+#    #+#             */
/*   Updated: 2022/11/27 23:21:55 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_circle	create_circle(double r, t_complex_number center)
{
	t_circle circle;

	circle.center = center;
	circle.r = r;
	circle.b = 1 / r;
	circle.bc = complex_mul(center, create_complex_number(circle.b, 0));
	return(circle);
}

t_circle	*symmetric_set(double x, double y, double radius)
{
	t_circle	*fni;
	
	fni = malloc(3 * sizeof(t_circle));
	if (!fni)
		return (0);
	double				mid = radius;
	double				c1r = -mid;
	t_complex_number	c1c = create_complex_number(x, y);
	t_circle			c1 = create_circle(c1r, c1c);
	
	double				c2r = mid/2;
	t_complex_number	c2c = create_complex_number(x - c2r, y);
	t_circle			c2 = create_circle(c2r, c2c);
	
	double				c3r = fabs(c1.r) - c2.r;
	double				c3x = c2.center.x + c2.r + c3r;
	double				c3y = c2.center.y;
	t_complex_number	c3c = create_complex_number(c3x, c3y);
	t_circle			c3 = create_circle(c3r, c3c);

	fni[0] = c1;
	fni[1] = c2;
	fni[2] = c3;
	return (fni);
}

t_circle	*a_symmetric_set(double x, double y, double radius)
{
	t_circle	*fni;
	
	fni = malloc(3 * sizeof(t_circle));
	if (!fni)
		return (0);
	double				mid = radius;
	double				c1r = -mid;
	t_complex_number	c1c = create_complex_number(x, y);
	t_circle			c1 = create_circle(c1r, c1c);
	
	double				c2r = mid / 1.25;
	t_complex_number	c2c = create_complex_number(x - mid + c2r, y);
	t_circle			c2 = create_circle(c2r, c2c);
	
	double				c3r = fabs(c1.r) - c2.r;
	double				c3x = c2.center.x + c2.r + c3r;
	double				c3y = c2.center.y;
	t_complex_number	c3c = create_complex_number(c3x, c3y);
	t_circle			c3 = create_circle(c3r, c3c);

	fni[0] = c1;
	fni[1] = c2;
	fni[2] = c3;
	return (fni);
}

t_complex_number	solve_equation(t_complex_number a, t_complex_number b, t_complex_number c)
{
	t_complex_number	s = complex_add(a, complex_add(b, c));
	t_complex_number	k1 = complex_mul(a, b);
	t_complex_number	k2 = complex_mul(a, c);
	t_complex_number	k3 = complex_mul(b, c);
	t_complex_number	ks = complex_add(k1, complex_add(k2, k3));
	
	return (complex_add(complex_mul(complex_sqrt(ks), create_complex_number(2, 0)), s));
}
