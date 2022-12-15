/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:10:10 by mgama             #+#    #+#             */
/*   Updated: 2022/12/14 21:17:51 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	show_commands_head(int t)
{
	ft_printf("\n\033[1;36m\033[4mCommands\033[0m\n");
	ft_printf("\n\033[1;34mYou have access to several actions to interact\
with the fractals.\n");
	ft_printf("\n\033[4;32mArrow keys:\033[0m %s",
		"\033[1;34mMove the content in the viewport.");
	ft_printf("\n\033[4;32mMouse wheel:\033[0m %s\n",
		"\033[1;34mZoom or unzoom into the viewport.");
}

void	show_commands(int t)
{
	show_commands_head(t);
	if (t == 1)
	{
		ft_printf("\n\033[4;32mW/S:\033[0m %s", "\033[1;34mIncrement or decrement \
respectively the real part of the formula.");
		ft_printf("\n\033[4;32mA/D:\033[0m %s\n", "\033[1;34mIncrement or decrement \
respectively the imaginary part of the formula.");
	}
	if (t != 3)
		ft_printf("\n\033[4;32mP:\033[0m %s",
			"\033[1;34mSwitch to the next color pallet.");
	if (t == 1)
	{
		ft_printf("\n\033[4;32mL:\033[0m %s",
			"\033[1;34mToggle mouse fractal tracking.");
		ft_printf("\n\033[4;32mO:\033[0m %s\n",
			"\033[1;34mPrint the current state.");
	}
	if (t == 3)
		ft_printf("\n\033[4;32mP:\033[0m %s", "\033[1;34mToggle fractal symmetry.");
	ft_printf("\n\033[4;32mI:\033[0m %s", "\033[1;34mToggle mouse zoom tracking.");
	ft_printf("\n\033[4;32mSPACE:\033[0m %s", "\033[1;34mReset zoom.");
	ft_printf("\n\033[4;32mESC:\033[0m %s\n", "\033[1;34mExit the program.");
	ft_printf("\n\033[0m");
}

static void	show_args_0(void)
{
	ft_printf("\n\n\033[1;31mWrong arguments!\n");
	ft_printf("\033[1;34mPlease select one of the following arguments \
['%s' or '%s', '%s' or '%s', '%s' or '%s', '%s' or '%s'].\n",
		"\033[1;32m\033[4mjulia\033[0m\033[1;34m",
		"\033[1;32m\033[4mj\033[0m\033[1;34m",
		"\033[1;32m\033[4mmandelbrot\033[0m\033[1;34m",
		"\033[1;32m\033[4mm\033[0m\033[1;34m",
		"\033[1;32m\033[4mapollonian\033[0m\033[1;34m",
		"\033[1;32m\033[4ma\033[0m\033[1;34m",
		"\033[1;32m\033[4mburningship\033[0m\033[1;34m",
		"\033[1;32m\033[4mb\033[0m\033[1;34m");
	ft_printf("\033[1;34mIf '\033[1;32m\033[4mjulia\033[0m\033[1;34m' is selected \
you need to specify \033[4mJulia set formula\033[0m\033[1;34m using two \
more arguments: a complex number witch his \033[4mreal\033[0m\033[1;34m \
part is separated of the \033[4mimaginary\033[0m\033[1;34m one [%s;%s] \
and [%s;%s](i not required).\n", "\033[1;32m\033[4m1\033[0m\033[1;34m",
		"\033[1;32m\033[4m-1\033[0m\033[1;34m",
		"\033[1;32m\033[4m1i\033[0m\033[1;34m",
		"\033[1;32m\033[4m-1i\033[0m\033[1;34m");
}

void	show_args(int nt)
{
	if (nt == 0)
		show_args_0();
	else if (nt == 1 || nt == 2)
	{
		if (nt == 1)
			ft_printf("\n\n\033[1;31mMissing arguments!\n");
		else
			ft_printf("\n\n\033[1;31mIncorrect arguments!\n");
		ft_printf("\033[1;34mYou have selected '\033[1;32m\033[4mjulia\033[0m\033[1;34m', \
you need to specify \033[4mJulia set formula\033[0m\033[1;34m using two arguments: \
a complex number witch his \033[4mreal\033[0m\033[1;34m part is separated of the \
\033[4mimaginary\033[0m\033[1;34m one [%s;%s] and [%s;%s]\
(i not required).\n",
			"\033[1;32m\033[4m1\033[0m\033[1;34m",
			"\033[1;32m\033[4m-1\033[0m\033[1;34m",
			"\033[1;32m\033[4m1i\033[0m\033[1;34m",
			"\033[1;32m\033[4m-1i\033[0m\033[1;34m");
	}
	exit(EXIT_FAILURE);
}
