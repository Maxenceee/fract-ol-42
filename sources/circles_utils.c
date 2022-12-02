/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circles_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:14:30 by mgama             #+#    #+#             */
/*   Updated: 2022/12/01 17:33:19 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_circle	get_adjacent(t_circle c1, t_circle c2, t_circle c3)
{
	t_complex_number	b1 = create_complex_number(c1.b, 0);
	t_complex_number	b2 = create_complex_number(c2.b, 0);
	t_complex_number	b3 = create_complex_number(c3.b, 0);
	t_complex_number	b4 = solve_equation(b1, b2, b3);
	t_complex_number	pos = complex_div(solve_equation(c1.bc, c2.bc, c3.bc), b4);

	return (create_circle(fabs(1 / b4.x), pos));
}

t_circle	flip_circle(t_circle c4, t_circle c1, t_circle c2, t_circle c3)
{
	double				bend = 2 * (c1.b + c2.b + c3.b) - c4.b;
	t_complex_number	center = complex_div(
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

void	recursive_circle(t_circle c1, t_circle c2, t_circle c3, t_circle c4, t_data *mlx)
{
	t_circle	cl1 = flip_circle(c2, c1, c3, c4);
	t_circle	cl2 = flip_circle(c3, c1, c2, c4);
	t_circle	cl3 = flip_circle(c4, c1, c2, c3);

	if (cl1.r > MIN_RADIUS)
	{
		draw_circle(cl1, mlx);
		recursive_circle(cl1, c1, c3, c4, mlx);
	}
	if (cl2.r > MIN_RADIUS)
	{
		draw_circle(cl2, mlx);
		recursive_circle(cl2, c1, c2, c4, mlx);
	}
	if (cl3.r > MIN_RADIUS)
	{
		draw_circle(cl3, mlx);
		recursive_circle(cl3, c1, c2, c3, mlx);
	}
}
