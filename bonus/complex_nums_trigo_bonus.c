/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_nums_trigo_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:47:53 by mgama             #+#    #+#             */
/*   Updated: 2023/12/22 11:31:30 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_complex_number	complex_sinh(t_complex_number n)
{
	double	a;
	double	b;

	a = sinh(n.x) * cos(n.y);
	b = cosh(n.x) * sin(n.y);
	return ((t_complex_number){.x = a, .y = b});
}

t_complex_number	complex_sin(t_complex_number n)
{
	double	a;
	double	b;

	a = sin(n.x) * cosh(n.y);
	b = cos(n.x) * sinh(n.y);
	return ((t_complex_number){.x = a, .y = b});
}

t_complex_number	complex_cos(t_complex_number n)
{
	double	a;
	double	b;

	a = cos(n.x) * cosh(n.y);
	b = sin(n.x) * sinh(n.y);
	return ((t_complex_number){.x = a, .y = b});
}

t_complex_number	complex_absv(t_complex_number a)
{
	return ((t_complex_number){.x = fabs(a.x), .y = fabs(a.y)});
}
