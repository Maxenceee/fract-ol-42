/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transitions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:24:07 by mgama             #+#    #+#             */
/*   Updated: 2023/02/19 02:09:06 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

double ft_maxf(double a, double b)
{
	if (a < b)
		return (b);
	return (a);
}

double ft_minf(double a, double b)
{
	if (a > b)
		return (b);
	return (a);
}

double ease_in_cubic(double t)
{
	return (t < .5 ? 2. * t * t : (4. - 2. * t) * t - 1.);
}

// double linear_distance(t_complex_number start, t_complex_number end)
// {
// 	return (sqrtf((end.x - start.x) * (end.x - start.x) + (end.y - start.y) * (end.y - start.y)));
// }

t_complex_number	transition_cubic(t_complex_number start_coords, t_complex_number end_coords, t_transition trans)
{
	// double delta = linear_distance(start_coords, end_coords);
	double l = (trans.current_time - trans.start_time) / trans.duration;
	double t = ft_minf(l, 1.);
	t_complex_number delta = create_complex_number(end_coords.x - start_coords.x, end_coords.y - start_coords.y);
	double ease = ease_in_cubic(t);
	t_complex_number a = create_complex_number(end_coords.x - (1 - ease) * delta.x, end_coords.y - (1 - ease) * delta.y);
	
	// ft_printf("d %f %f %f\n", t, delta.x, delta.y);
	// ft_printf("a %f %f %f\n", ease, a.x, a.y);
	return (a);
}

void	transition_event(int key_code, void *param)
{
	t_data	*mlx;

	mlx = (t_data *)param;
	if (key_code == 6)
	{
		t_transition trans;
		struct timeval  tv;
		gettimeofday(&tv, NULL);
		double time_in_mill = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
		
		trans.start_time = time_in_mill;
		trans.duration = 500;
		trans.current_time = time_in_mill;
		mlx->current_transition = trans;
		mlx->transition_req = 1;
	}
}

void	transition_hook(void *param)
{
	t_data	*mlx;

	mlx = (t_data *)param;
	struct timeval  tv;
	gettimeofday(&tv, NULL);
	double time_in_mill = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	mlx->current_transition.current_time = time_in_mill;
	if (mlx->transition_req && mlx->current_transition.current_time >= mlx->current_transition.start_time && mlx->current_transition.current_time <= mlx->current_transition.start_time + mlx->current_transition.duration)
	{
		// printf("time %f %f\n", mlx->current_transition.current_time, mlx->current_transition.start_time);
		t_complex_number start = create_complex_number(0, 0);
		t_complex_number end = create_complex_number(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		t_complex_number t = transition_cubic(start, end, mlx->current_transition);
		// mlx_update_image(mlx);
		
		my_mlx_pixel_put(mlx, t.x, t.y, 0XFF0000);
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
		// mlx->transition_req = 0;
	}
}