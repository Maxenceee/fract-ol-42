/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:56:03 by mgama             #+#    #+#             */
/*   Updated: 2024/02/21 19:28:07 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

#ifdef __APPLE__

void	ft_destroy_display(void *mlx)
{
	(void)mlx;
}

#else

void	ft_destroy_display(void *mlx)
{
	mlx_destroy_display(mlx);
}

#endif /* __APPLE__ */
