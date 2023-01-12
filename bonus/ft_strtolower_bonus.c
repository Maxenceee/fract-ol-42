/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:24:52 by mgama             #+#    #+#             */
/*   Updated: 2023/01/12 16:36:01 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	ft_frtolower(int num)
{
	if (num >= 65 && num <= 90)
		num += 32;
	return (num);
}

char	*ft_frstrtolower(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		str[i] = ft_tolower(str[i]);
	}
	return (str);
}
