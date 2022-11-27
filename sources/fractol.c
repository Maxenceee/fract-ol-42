/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:26:13 by mgama             #+#    #+#             */
/*   Updated: 2022/11/27 23:47:44 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	switch_mlx_image(t_data *mlx)
{
	static int	img_type;

	if (!img_type)
		img_type = 0;
	// printf("switch %d scale %f\n", img_type, mlx->scale);
	// print_complex(mlx->formula);
	// printf("Center offset ");
	// print_complex(mlx->center_offset);
	// printf("\n");
	if (img_type == 0)
	{
		mlx->curr_img = mlx->img_1;
		img_type = 1;
	}
	else if (img_type == 1)
	{
		mlx->curr_img = mlx->img_2;
		img_type = 0;
	}
	mlx->addr = mlx_get_data_addr(mlx->curr_img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
	(*mlx->fractol_function)(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->curr_img, 0, 0);
}

void	init_fractol(void (*f)(t_data*), t_data *mlx)
{
	mlx->fractol_function = *f;
	mlx->scale = 0.;
	mlx->key_pressed = 0;
	mlx->pallet_type = 0;
	mlx->center_offset = create_complex_number(0, 0);
	init_pallets(mlx);
	switch_mlx_image(mlx);
}

int	ft_fractol(char *type, t_complex_number initial_offset)
{
	t_data	mlx;
	
	if (initial_offset.x > 1 || initial_offset.x < -1 || initial_offset.y > 1 || initial_offset.y < -1)
		show_args(2);
    mlx.mlx = mlx_init();
    mlx.window = mlx_new_window(mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fract-ol");

	mlx.formula = initial_offset;
	mlx.no_pallet = 0;
	// mlx.formula = create_complex_number(0.28, 0);
	// mlx.formula = create_complex_number(-0.23, 0.7);
	// mlx.formula = create_complex_number(-0.28, 0.7);
	// mlx.formula = create_complex_number(-0.23, 0.71);
	// mlx.formula = create_complex_number(-0.249, 0.749);

	mlx.img_1 = mlx_new_image(mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx.img_2 = mlx_new_image(mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);

	mlx_mouse_hook(mlx.window, &mouse_event, &mlx);
	mlx_hook(mlx.window, 17, 1L << 0, &stop_mlx, &mlx);
	mlx_hook(mlx.window, 2, 0L, &key_down_event, &mlx);
	mlx_hook(mlx.window, 3, 0L, &key_up_event, &mlx);

	if (ft_strcmp(type, "julia") == 0)
	{
		printf("\n\n\033[1;31mStarting calculate julia set for Z^2 %+f %+fi%s\n", mlx.formula.x, mlx.formula.y, "\n\033[0m");
		show_commands(1);
		init_fractol(&julia_set, &mlx);
	}
	else if (ft_strcmp(type, "mandelbrot") == 0)
	{
		show_commands(2);
		init_fractol(&mandelbrot_set, &mlx);
	}
	else if (ft_strcmp(type, "apollonian-gasket") == 0)
	{
		mlx.no_pallet = 1;
		show_commands(3);
		init_fractol(&apollonian_gasket_set, &mlx);
	}
	else
		exit(EXIT_FAILURE);

	mlx_loop_hook(mlx.mlx, &loop_hook_events, &mlx);
	/*
	** LOOP function 
	*/
    mlx_loop(mlx.mlx);
	return (0);
}

void	show_commands(int t)
{
	printf("\n\033[1;36mCommands\n");
	printf("\n\033[1;34mYou have access to several actions to interact with the fractals.\n");
	printf("\n\033[4;32mArrow keys:\033[0m %s", "\033[1;34mMove the content in the viewport.");
	printf("\n\033[4;32mMouse wheel:\033[0m %s\n", "\033[1;34mZoom or unzoom into the viewport.");
	if (t != 3)
	{
		printf("\n\033[4;32mZ/S:\033[0m %s", "\033[1;34mIncrement or decrement respectively the real part of the formula.");
		printf("\n\033[4;32mQ/D:\033[0m %s\n", "\033[1;34mIncrement or decrement respectively the imaginary part of the formula.");
		printf("\n\033[4;32mP:\033[0m %s", "\033[1;34mSwitch the color pallet.");
	}
	else
		printf("\n\033[4;32mP:\033[0m %s", "\033[1;34mToggle fractal symmetry.");
	printf("\n\033[4;32mESC:\033[0m %s\n", "\033[1;34mExit the program.");
	printf("\n\033[0m");
}

void	show_args(int nt)
{
	if (nt == 0)
	{
		printf("\n\033[1;31mWrong arguments!\n");
		printf("\033[1;34mPlease select one of the following arguments ['%s' or '%s', '%s' or '%s', '%s' or '%s'].\n", "\033[1;32m\033[4mjulia\033[0m\033[1;34m", "\033[1;32m\033[4mj\033[0m\033[1;34m", "\033[1;32m\033[4mmandelbrot\033[0m\033[1;34m", "\033[1;32m\033[4mm\033[0m\033[1;34m", "\033[1;32m\033[4mapollonian-gasket\033[0m\033[1;34m", "\033[1;32m\033[4ma\033[0m\033[1;34m");
		printf("\033[1;34mIf '\033[1;32m\033[4mjulia\033[0m\033[1;34m' is selected you need to specify \033[4mJulia-set\033[0m\033[1;34m formula using two more arguments: a complex number witch his \033[4mreal\033[0m\033[1;34m part is separated of the \033[4mimaginary\033[0m\033[1;34m one [%s;%s] and [%s;%s](i not required).\n", "\033[1;32m\033[4m1\033[0m\033[1;34m", "\033[1;32m\033[4m-1\033[0m\033[1;34m", "\033[1;32m\033[4m1i\033[0m\033[1;34m", "\033[1;32m\033[4m-1i\033[0m\033[1;34m");
	}
	else if (nt == 1 || nt == 2)
	{
		if (nt == 1)
			printf("\n\033[1;31mMissing arguments!\n");
		else
			printf("\n\033[1;31mIncorrect arguments!\n");
		printf("\033[1;34mYou have selected '\033[1;32m\033[4mjulia\033[0m\033[1;34m', you need to specify \033[4mJulia-set\033[0m\033[1;34m formula using two arguments: a complex number witch his \033[4mreal\033[0m\033[1;34m part is separated of the \033[4mimaginary\033[0m\033[1;34m one [%s;%s] and [%s;%s](i not required).\n", "\033[1;32m\033[4m1\033[0m\033[1;34m", "\033[1;32m\033[4m-1\033[0m\033[1;34m", "\033[1;32m\033[4m1i\033[0m\033[1;34m", "\033[1;32m\033[4m-1i\033[0m\033[1;34m");
	}
	exit(EXIT_FAILURE);
}

void	fractal_selector(int argc, char **argv)
{
	t_complex_number offset_f;
	
	if (ft_strstr(ft_strtolower(argv[1]), "julia") || ft_strstr(ft_strtolower(argv[1]), "j"))
	{
		if (argc > 3)
			offset_f = create_complex_number(ft_atof(argv[2]), ft_atof(argv[3]));
		else
			show_args(1);
		ft_fractol("julia", offset_f);
	}
	else if (ft_strstr(ft_strtolower(argv[1]), "mandelbrot") || ft_strstr(ft_strtolower(argv[1]), "m"))
		ft_fractol("mandelbrot", create_complex_number(0, 0));
	else if (ft_strstr(ft_strtolower(argv[1]), "apollonian-gasket") || ft_strstr(ft_strtolower(argv[1]), "a"))
		ft_fractol("apollonian-gasket", create_complex_number(0, 0));
	else
		show_args(0);
}

int main(int argc, char **argv)
{	
	if (argc > 1)
		fractal_selector(argc, argv);
	else
		show_args(0);
	return (0);
}