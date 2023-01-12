/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:42:53 by mgama             #+#    #+#             */
/*   Updated: 2023/01/12 16:35:59 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

static int	is_in(char *sr, char *pr, int idx)
{
	int	i;

	i = 0;
	while (pr[i] != '\0' && sr[idx + i] != '\0')
	{
		if (pr[i] != sr[idx + i])
			return (0);
		i++;
	}
	if (sr[idx + i] == '\0' && pr[i] != '\0')
		return (0);
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (is_in(str, to_find, i))
		{
			return (str + i);
		}
		i++;
	}
	return (0);
}
