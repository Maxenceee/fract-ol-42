/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:24:52 by mgama             #+#    #+#             */
/*   Updated: 2022/11/27 22:17:49 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_tolower(int num)
{
	if (num >= 65 && num <= 90)
		num += 32;
	return (num);
}

char	*ft_strtolower(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		str[i] = ft_tolower(str[i]);
	}
	return (str);
}