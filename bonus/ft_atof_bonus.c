/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:30:04 by mgama             #+#    #+#             */
/*   Updated: 2023/01/12 16:35:47 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

double	ft_get_floating_part(char *s, double a, int c, int sign)
{
	int		e;

	e = 0;
	if (c == '.')
		c = *s++;
	while (c != '\0' && ft_isdigit(c))
	{
		a = a * 10.0 + (c - '0');
		e = e - 1;
		c = *s++;
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

double	ft_atof(char *s)
{
	double	a;
	int		c;
	int		sign;

	sign = 0;
	a = 0.0;
	if (*s == '-')
	{
		sign++;
		s++;
	}
	else if (*s == '+')
		s++;
	c = *s++;
	while (c != '\0' && ft_isdigit(c))
	{
		a = a * 10.0 + (c - '0');
		c = *s++;
	}
	return (ft_get_floating_part(s, a, c, sign));
}
