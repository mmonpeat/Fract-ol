/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:03:25 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/01 15:51:00 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	read_key(int press_key, t_all *all)
{
	if (press_key == ESC)
		exit_window(&all->wind);
	else if (press_key == ARROW_LEFT || press_key == A)
	{
		printf("ARROW_LEFT: %f\n", all->mv.x);
		all->mv.x -= 1.0;
		printf("1 ARROW_LEFT: %f\n", all->mv.x);
		mandelbrot(&all->fractal, &all->img, &all->mv, &all->wind);
		printf("2 ARROW_LEFT: %f\n", all->mv.x);
	}
	else if (press_key == ARROW_RIGHT || press_key == D)
	{
		printf("ARROW_RIGHT: %f\n", all->mv.x);
		all->mv.x += 1.0;
		printf("1 ARROW_RIGHT: %f\n", all->mv.x);
		mandelbrot(&all->fractal, &all->img, &all->mv, &all->wind);
		printf("2 ARROW_RIGHT: %f\n", all->mv.x);
	}
	else if (press_key == ARROW_UP || press_key == WW)
	{
		printf("ARROW_UP\n");
		all->mv.y += 0.1;
		mandelbrot(&all->fractal, &all->img, &all->mv, &all->wind);
	}
	else if (press_key == ARROW_DOWN || press_key == S)
	{
		all->mv.y -= 0.1;
		printf("ARROW_DOWN\n");
		mandelbrot(&all->fractal, &all->img, &all->mv, &all->wind);
	}
	else if (press_key == NP_MIN)
	{
		printf("Dis iter: %i\n", all->mv.ctrl_iter);
		all->mv.ctrl_iter -= 10;
		printf("1 Dis iter: %i\n", all->mv.ctrl_iter);
		mandelbrot(&all->fractal, &all->img, &all->mv, &all->wind);
		printf("2Dis iter: %i\n", all->mv.ctrl_iter);
	}
	else if (press_key == NP_PLU)
	{
		printf("Aug iter: %i\n", all->mv.ctrl_iter);
		all->mv.ctrl_iter += 10;
		printf("1Aug iter: %i\n", all->mv.ctrl_iter);
		mandelbrot(&all->fractal, &all->img, &all->mv, &all->wind);
		printf("2Aug iter: %i\n", all->mv.ctrl_iter);
	}
	return (0);
}

// int	mouse_hook(int x, int y, t_all *all)
// {
// 	if (all->pict.movable && !all->pict.mov_lock)
// 	{
// 		all->mouse_pos.x = scale(x, all->mlx.win_size.x,
// 				all->pict.pos.x, all->pict.size.x);
// 		all->mouse_pos.y = scale(y, all->mlx.win_size.y,
// 				all->pict.pos.y, all->pict.size.y);
// 		draw_win(all);
// 	}
// 	return (0);
// }

// int	scroll_hook(int button, int x, int y, t_all *all)
// {
	
// }

int	exit_window(t_win *wind)
{
	if (wind)
		mlx_destroy_window (wind->mlx_ptr, wind->win_ptr);
	exit(EXIT_SUCCESS);
}
