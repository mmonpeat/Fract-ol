/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:03:25 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/04 19:34:45 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	read_key(int press_key, t_all *all)
{
	static t_palette	colors[N_PALETTES] = {pastel_colors, \
		psychedelic_colors};
	static int			i;

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
	else if (press_key == CTRL)
	{
		i++;
		all->mv.col = colors[i % 2];
	}
	recompile_fractal(all);
	return (0);
}

int	mouse_hook(int x, int y, t_all *all)
{
	if (x < W && x >= 0 && y < H && y >= 0 && all->mv.stop == 0)
	{//convertim a complex
		all->fractal.x_c = (x - all->img.w / 1.5 + all->mv.x) * 3.0 / 
			(all->img.w * all->mv.z);
		all->fractal.y_c = (y - all->img.h / 1.5 + all->mv.y) * 3.0 / 
			(all->img.h * all->mv.z);
	}
	if (all->mv.stop == 0)
		recompile_fractal(all);
	return (0);
}

int	scroll_hook(int button, int x, int y, t_all *all)
{
	if (button == MOUSE_SCROLL_UP)
	{
		(void)y;
		all->mv.z += 0.5;
		all->mv.x += x - ((W / 2) + all->mv.x);
		all->mv.y += y - ((H / 2) + all->mv.y);
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		all->mv.z -= 0.5;
		all->mv.x -= x - ((W / 2) + all->mv.x);
		all->mv.y -= y - ((H / 2) + all->mv.y);
	}
	if (button == MOUSE_LEFT_BUTTON)
	{
		if (all->mv.stop == 0)
			all->mv.stop = 1;
		else
			all->mv.stop = 0;
	}
	if (all->mv.stop == 0 || button == MOUSE_SCROLL_UP || \
		button == MOUSE_SCROLL_DOWN)
		recompile_fractal(all);
	return (0);
}

int	exit_window(t_win *wind)
{
	if (wind)
		mlx_destroy_window (wind->mlx_ptr, wind->win_ptr);
	exit(EXIT_SUCCESS);
}
