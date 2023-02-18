/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:13:26 by mgama             #+#    #+#             */
/*   Updated: 2023/02/18 18:08:10 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

static void	print_state(t_data *mlx)
{
	ft_printf("\n\033[1;35mCurrent fractal: \033[4m%s%s\n",
		mlx->fractal_list[mlx->current_fractal_type].fractal_name,
		"\033[0m");
	if (mlx->fractal_list[mlx->current_fractal_type].has_formula)
		ft_printf("\033[1;35mCurrent formula: Z^%d %+.3f %+.3fi %s\n",
			mlx->fractal_list[mlx->current_fractal_type].formula_exp,
			mlx->formula.x, mlx->formula.y, "\033[0m");
	if (mlx->fractal_list[mlx->current_fractal_type].formula_exp != -1
		&& !mlx->fractal_list[mlx->current_fractal_type].has_formula)
		ft_printf("\033[1;35mCurrent exponent: %d %s\n",
			mlx->fractal_list[mlx->current_fractal_type].formula_exp,
			"\033[0m");
}

int	stop_mlx(t_data *mlx)
{
	if (mlx->img != NULL)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->pallets->pallet != NULL)
		free(mlx->pallets->pallet);
	if (mlx->fractal_list != NULL)
		free(mlx->fractal_list);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_down_event(int key_code, void *param)
{
	t_data	*mlx;

	mlx = (t_data *)param;
	if (key_code == 53)
	{
		stop_mlx(mlx);
	}
	if (mlx->is_home)
		return (0);
	arrow_key_events(key_code, mlx);
	arrow_letter_events(key_code, mlx);
	return (0);
}

int	key_up_event(int key_code, void *param)
{
	t_data	*mlx;

	mlx = (t_data *)param;
	if (mlx->is_home)
		return (0);
	if (mlx->key_pressed == 1)
		mlx->key_pressed = 0;
	pallet_events(key_code, mlx);
	variants_events(key_code, mlx);
	key_events(key_code, mlx);
	if (key_code == 31)
		print_state(mlx);
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
	return (0);
}

int	loop_hook_events(void *param)
{
	t_data	*mlx;

	mlx = (t_data *)param;
	if (mlx->is_home)
		return (0);
	if (mlx->key_pressed == 1)
		mlx_update_image(mlx);

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
	return (0);
}
