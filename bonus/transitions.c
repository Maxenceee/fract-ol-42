/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transitions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:24:07 by mgama             #+#    #+#             */
/*   Updated: 2023/02/18 17:09:42 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

double ft_minf(double a, double b)
{
	if (a > b)
		return (b);
	return (a);
}

double ease_in_cubic(double t)
{
	return (t < .5 ? 2. * t * t : (4. - 2. * t) * t - 1.);
}

// double linear_distance(t_complex_number start, t_complex_number end)
// {
// 	return (sqrtf((end.x - start.x) * (end.x - start.x) + (end.y - start.y) * (end.y - start.y)));
// }

t_complex_number	transition_cubic(t_complex_number start_coords, t_complex_number end_coords, t_transition trans)
{
	// double delta = linear_distance(start_coords, end_coords);
	double l = (trans.current_time - trans.start_time) / trans.duration;
	double t = ft_minf(l, 1.);
	t_complex_number delta = create_complex_number(end_coords.x - start_coords.x, end_coords.y - start_coords.y);
	double ease = ease_in_cubic(t);
	t_complex_number a = create_complex_number(end_coords.x - (1 - ease) * delta.x, end_coords.y - (1 - ease) * delta.y);
	
	// ft_printf("d %f %f %f\n", t, delta.x, delta.y);
	// ft_printf("a %f %f %f\n", ease, a.x, a.y);
	return (a);
}