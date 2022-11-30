/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:30:04 by mgama             #+#    #+#             */
/*   Updated: 2022/11/29 20:50:13 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double  ft_atof(const char *s)
{
	double	a;
	int		e;
	int		c;
	int		sign;
	
	sign = 0;
	a = 0.0;
	e = 0;
	if (*s == '-')
	{
		sign++;
		s++;
	}
	else if (*s == '+')
		s++;
	while ((c = *s++) != '\0' && ft_isdigit(c))
		a = a*10.0 + (c - '0');
	if (c == '.')
		while ((c = *s++) != '\0' && ft_isdigit(c))
		{
			a = a*10.0 + (c - '0');
			e = e-1;
		}
	while (e < 0)
	{
		a *= 0.1;
		e++;
	}
	if (sign > 0)
		a = -a;
	return (a);
}
