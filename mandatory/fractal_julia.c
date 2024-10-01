/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:28:46 by mgama             #+#    #+#             */
/*   Updated: 2024/10/01 22:11:57 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline void	julia_set(register t_data *mlx, register t_screen_dim s_d)
{
	int					y;
	int					x;
	register t_color	pallet;
	register int		pix;
	double				inv_scale;

	y = -1;
	handle_exp_variants(mlx);
	pallet = mlx->pallets[mlx->pallet_type];
	inv_scale = 1 / mlx->scale;
	while (++y < s_d.height)
	{
		x = -1;
		while (++x < s_d.width)
		{
			pix = calcule_julia_series(
					convert_corner_to_center(
						create_complex_number(s_d.left + x, s_d.top + y),
						mlx->center_offset, inv_scale,
						create_complex_number(s_d.center_x, s_d.center_y)),
					mlx->formula, mlx);
			my_mlx_pixel_put(mlx, s_d.left + x, s_d.top + y,
				get_color(pix, pallet.pallet, pallet.pallet_length));
		}
	}
}

inline int	calcule_julia_series(t_complex_number point,
	t_complex_number point_offset, t_data *mlx)
{
	register t_complex_number	num;
	register t_complex_number	temp_num;
	int							i;

	num = create_complex_number(point.x, point.y);
	i = 0;
	while (modulus_complex_2(num) < 4. && i < MAX_ITER)
	{
		temp_num = num;
		num = complex_add(
				complex_rational_pow(temp_num,
					mlx->fractal_list[mlx->curr_fractal_type].formula_exp),
				point_offset);
		i++;
	}
	return (i);
}

inline int	handle_exp_variants(t_data *mlx)
{
	if (mlx->next_variant == 1)
		mlx->fractal_list[mlx->curr_fractal_type].formula_exp++;
	if (mlx->prev_variant == 1
		&& mlx->fractal_list[mlx->curr_fractal_type].formula_exp > 1)
		mlx->fractal_list[mlx->curr_fractal_type].formula_exp--;
	return (mlx->fractal_list[mlx->curr_fractal_type].formula_exp);
}

inline t_complex_number	convert_corner_to_center(t_complex_number point,
	t_complex_number mouse_offset, double inv_scale, t_complex_number mids)
{
	return ((t_complex_number){
		.x = (point.x - mids.x) * inv_scale + mouse_offset.x,
		.y = (point.y - mids.y) * inv_scale + mouse_offset.y});
}
