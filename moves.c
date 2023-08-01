/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:03:25 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/01 18:54:18 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	read_key(int press_key, t_all *all)
{
	if (press_key == ESC)
		exit_window(&all->wind);
	else if (press_key == ARROW_LEFT || press_key == A)
		all->mv.x += 0.1;
	else if (press_key == ARROW_RIGHT || press_key == D)
		all->mv.x -= 0.1;
	else if (press_key == ARROW_UP || press_key == WW)
		all->mv.y += 0.1;
	else if (press_key == ARROW_DOWN || press_key == S)
		all->mv.y -= 0.1;
	else if (press_key == NP_MIN)
	{
		printf("Dis iter: %i\n", all->mv.ctrl_iter);
		all->mv.ctrl_iter -= 10;
		all->mv.z -= 1.0;
		printf("1 Dis iter: %i\n", all->mv.ctrl_iter);
		printf("Zoo_out: %f\n", all->mv.z);
	}
	else if (press_key == NP_PLU)
	{
		printf("Aug iter: %i\n", all->mv.ctrl_iter);
		all->mv.ctrl_iter += 10;
		all->mv.z += 1.0;
		printf("1Aug iter: %i\n", all->mv.ctrl_iter);
		printf("Zoom_in: %f\n", all->mv.z);
	}
	mandelbrot(&all->fractal, &all->img, &all->mv, &all->wind);
	return (0);
}

int	mouse_hook(int x, int y, t_all *all)
{
	double	x_fraction;
	double	x_range;
	double	y_fraction;
	double	y_range;

	x_fraction = 0;
	x_range = 0;
	y_fraction = 0;
	y_range = 0;
	if (all->fractal.iter > 0)
	{
		x_fraction = (double)x / all->wind.w;
		x_range = all->fractal.x_e - all->fractal.x_s;
		all->mouse.x = all->fractal.x_s - (x_fraction * x_range);
		y_fraction = (double)y / all->wind.h;
		y_range = all->fractal.y_e - all->fractal.y_s;
		all->mouse.y = all->fractal.y_s - (y_fraction * y_range);
		//factal
		// all->fractal.fractal_function(&all->fractal);
	}
	// printf("x: %f y: %f\n", all->mouse.x, all->mouse.y);
	mandelbrot(&all->fractal, &all->img, &all->mv, &all->wind);
	return (0);
}

// int	scroll_hook(int button, int x, int y, t_all *all)
// {
	
// }

int	exit_window(t_win *wind)
{
	if (wind)
		mlx_destroy_window (wind->mlx_ptr, wind->win_ptr);
	exit(EXIT_SUCCESS);
}
