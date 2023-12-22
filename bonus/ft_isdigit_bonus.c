/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:30:32 by mgama             #+#    #+#             */
/*   Updated: 2023/12/22 11:38:35 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

int	ft_isdigit(int num)
{
	if (num < 48 || num > 57)
		return (0);
	return (1);
}

int	ft_isstrdigit(char *num)
{
	size_t	len;

	len = ft_strlen(num);
	while (len-- > 0)
	{
		if ((num[len] < 48 || num[len] > 57) && num[len] != 46
			&& (len != 0 && num[len] == 45))
			return (0);
	}
	return (1);
}
