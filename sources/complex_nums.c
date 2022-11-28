/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_nums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:46:28 by mgama             #+#    #+#             */
/*   Updated: 2022/11/28 21:08:38 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_complex(t_complex_number num)
{
	printf("x=%f, y=%f\n", num.x, num.y);
}

t_complex_number	create_complex_number(double x, double y)
{
	t_complex_number num;
	
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
	double	a = fabs(x);
	double	b = fabs(y);

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
