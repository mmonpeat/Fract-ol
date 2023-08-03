/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:03:25 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/03 16:49:50 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	read_key(int press_key, t_all *all)
{
	if (press_key == ESC)
		exit_window(&all->wind);
	else if (press_key == ARROW_LEFT || press_key == A)
		all->mv.x -= 20.0;
	else if (press_key == ARROW_RIGHT || press_key == D)
		all->mv.x += 20.0;
	else if (press_key == ARROW_UP || press_key == WW)
		all->mv.y -= 20.0;
	else if (press_key == ARROW_DOWN || press_key == S)
		all->mv.y += 20.0;
	else if (press_key == NP_MIN)
		all->mv.i -= 50;
	else if (press_key == NP_PLU)
		all->mv.i += 50;
	ship(&all->fractal, &all->img, &all->mv, &all->wind);
	return (0);
}

// int	mouse_hook(int x, int y, t_all *all)
// {
// 	double	x_fraction;
// 	double	x_range;
// 	double	y_fraction;
// 	double	y_range;

// 	x_fraction = 0;
// 	x_range = 0;
// 	y_fraction = 0;
// 	y_range = 0;
// 	if (all->fractal.iter > 0)
// 	{
// 		x_fraction = (double)x / all->wind.w;
// 		x_range = all->fractal.x_e - all->fractal.x;
// 		all->mouse.x = all->fractal.x - (x_fraction * x_range);
// 		y_fraction = (double)y / all->wind.h;
// 		y_range = all->fractal.y_e - all->fractal.y;
// 		all->mouse.y = all->fractal.y - (y_fraction * y_range);
// 		//factal
// 		// all->fractal.fractal_function(&all->fractal);
// 	}
// 	// printf("x: %f y: %f\n", all->mouse.x, all->mouse.y);
// 	mandelbrot(&all->fractal, &all->img, &all->mv, &all->wind);
// 	return (0);
// }

int	scroll_hook(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	printf("x: %i y: %i\n", x, y);
	if (button == MOUSE_SCROLL_UP)
	{
		all->mv.z += 0.5;
		// printf("Zoom in: %f x: %i, y:%i\n", all->mv.z, x, y);
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		all->mv.z -= 0.5;
		// printf("Zoom out: %f, x: %i, y:%i\n", all->mv.z, x, y);
	}
	ship(&all->fractal, &all->img, &all->mv, &all->wind);
	return (0);
}

int	exit_window(t_win *wind)
{
	if (wind)
		mlx_destroy_window (wind->mlx_ptr, wind->win_ptr);
	exit(EXIT_SUCCESS);
}
