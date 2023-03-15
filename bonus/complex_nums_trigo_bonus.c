/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_nums_trigo_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:47:53 by mgama             #+#    #+#             */
/*   Updated: 2023/02/19 19:02:42 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

t_complex_number	complex_sinh(t_complex_number a)
{
	return (create_complex_number(sinh(a.x) * cos(a.y),
			cosh(a.x) * sin(a.y)));
}

t_complex_number	complex_sin(t_complex_number a)
{
	return (create_complex_number(sin(a.x) * cos(a.y),
			-1 * cos(a.x) * sin(a.y)));
}

t_complex_number	complex_cos(t_complex_number a)
{
	return (create_complex_number(cos(a.x) * cos(a.y),
			-1 * sin(a.x) * sin(a.y)));
}