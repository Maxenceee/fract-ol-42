/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_test_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:13:52 by mgama             #+#    #+#             */
/*   Updated: 2026/02/06 00:43:08 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_TEST_BONUS_H
# define FRACTOL_TEST_BONUS_H

# include "fractol_bonus.h"
# include <float.h>

#define TESTING_CYCLES 1000

static struct timespec g_start, g_end;
static double g_total_time = 0;
static double g_min_time = DBL_MAX;
static double g_max_time = 0;
static int    g_count = 0;

static struct timespec g_start, g_end;

static inline void	start_timer(void)
{
    clock_gettime(CLOCK_MONOTONIC, &g_start);
}

static inline void	end_timer(void)
{
    clock_gettime(CLOCK_MONOTONIC, &g_end);
    double current = (g_end.tv_sec - g_start.tv_sec) + 
                     (g_end.tv_nsec - g_start.tv_nsec) * 1e-9;

    g_total_time += current;
    if (current < g_min_time) g_min_time = current;
    if (current > g_max_time) g_max_time = current;
    g_count++;
}

static inline void	display_render_time(const char *fractal_name)
{
	if (g_count == 0) return;

    double avg = g_total_time / g_count;
    double diff = g_max_time - g_min_time;

    printf("- Metrics for %s (%d cycles)\n", fractal_name, g_count);
    printf("  Average : %.6f s\n", avg);
    printf("  Min     : %.6f s\n", g_min_time);
    printf("  Max     : %.6f s\n", g_max_time);
    printf("  Diff    : %.6f s\n", diff);
    printf("--------------------------------------\n");

    g_total_time = 0;
    g_min_time = DBL_MAX;
    g_max_time = 0;
    g_count = 0;
}

static inline t_complex_number random_formula(void)
{
	t_complex_number formula;
	formula.x = ((double)rand() / RAND_MAX) * 4.0 - 2.0;
	formula.y = ((double)rand() / RAND_MAX) * 4.0 - 2.0;
	return formula;
}

static inline double random_scale(void)
{
	return ((double)rand() / RAND_MAX) * 2 * INITIAL_SCALE;
}

static inline void render_and_time(t_data *mlx)
{
	start_timer();
	mlx_update_image_multitp(mlx);
	// mlx_do_sync(mlx->mlx);
	end_timer();
}

int	ft_fractol_testing(t_data *mlx, int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	int	type;
	int cycles;

	if (!register_fractals(mlx))
		exit(EXIT_FAILURE);
	type = 0;
	while (type < 2)
	{
		cycles = 0;
		double type_start_time = g_total_time;
		printf("\n--- Testing %s ---\n", mlx->fractal_list[type].fractal_name);
		mlx->curr_fractal_type = type;
		while (cycles < TESTING_CYCLES)
		{
			mlx->formula = random_formula();
			mlx->scale = random_scale();
			render_and_time(mlx);
			cycles++;
		}
		double type_elapsed = g_total_time - type_start_time;
		display_render_time(mlx->fractal_list[type].fractal_name);
		printf("  Total elapsed time: %.6f s\n", type_elapsed);
		printf("--------------------------------------\n");
		type++;
	}
	return (0);
}

#endif /* FRACTOL_TEST_BONUS_H */
