/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circles_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:14:30 by mgama             #+#    #+#             */
/*   Updated: 2023/01/12 16:35:12 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

t_circle	get_adjacent(t_circle c1, t_circle c2, t_circle c3)
{
	t_complex_number	b1;
	t_complex_number	b2;
	t_complex_number	b3;
	t_complex_number	b4;
	t_complex_number	pos;

	b1 = create_complex_number(c1.b, 0);
	b2 = create_complex_number(c2.b, 0);
	b3 = create_complex_number(c3.b, 0);
	b4 = solve_equation(b1, b2, b3);
	pos = complex_div(solve_equation(c1.bc, c2.bc, c3.bc), b4);
	return (create_circle(fabs(1 / b4.x), pos));
}

t_circle	flip_circle(t_circle c4, t_circle c1, t_circle c2, t_circle c3)
{
	double				bend;
	t_complex_number	center;

	bend = 2 * (c1.b + c2.b + c3.b) - c4.b;
	center = complex_div(
			complex_sub(
				complex_mul(
					complex_add(
						complex_add(c1.bc, c2.bc),
						c3.bc),
					create_complex_number(2, 0)),
				c4.bc),
			create_complex_number(bend, 0));
	return (create_circle(1 / bend, center));
}

t_r_apollonian_c	create_recursive_circle(t_circle c1, t_circle c2,
	t_circle c3, t_circle c4)
{
	t_r_apollonian_c	c;

	c.c1 = c1;
	c.c2 = c2;
	c.c3 = c3;
	c.c4 = c4;
	return (c);
}

void	recursive_circle(t_r_apollonian_c circles,
	t_data *mlx, t_screen_dim s_dims)
{
	t_circle	cl1;
	t_circle	cl2;
	t_circle	cl3;

	cl1 = flip_circle(circles.c2, circles.c1, circles.c3, circles.c4);
	cl2 = flip_circle(circles.c3, circles.c1, circles.c2, circles.c4);
	cl3 = flip_circle(circles.c4, circles.c1, circles.c2, circles.c3);
	if (cl1.r > MIN_RADIUS)
	{
		draw_circle(cl1, mlx, s_dims);
		recursive_circle(create_recursive_circle(cl1, circles.c1,
				circles.c3, circles.c4), mlx, s_dims);
	}
	if (cl2.r > MIN_RADIUS)
	{
		draw_circle(cl2, mlx, s_dims);
		recursive_circle(create_recursive_circle(cl2, circles.c1,
				circles.c2, circles.c4), mlx, s_dims);
	}
	if (cl3.r > MIN_RADIUS)
	{
		draw_circle(cl3, mlx, s_dims);
		recursive_circle(create_recursive_circle(cl3, circles.c1,
				circles.c2, circles.c3), mlx, s_dims);
	}
}
