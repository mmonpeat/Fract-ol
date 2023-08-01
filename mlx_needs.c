/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_needs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:54:27 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/01 13:45:45 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	new_program(int w, int h, char *str, t_win *wind)
{
	wind->mlx_ptr = mlx_init();
	wind->win_ptr = mlx_new_window(wind->mlx_ptr, w, h, str);
	if (!wind->mlx_ptr)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	new_img(int w, int h, t_img *img, void *mlx_ptr)
{
	img->img_ptr = mlx_new_image(mlx_ptr, w, h);
	if (!img->img_ptr)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	img->addr = mlx_get_data_addr(img->img_ptr, 
			&(img->bpp), &(img->line_len), 
			&(img->endian));
	img->w = w;
	img->h = h;
	return (1);
}

void	my_put_pixel_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img->w && y < img->h)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *) dst = color;
	}
}

// static void	add_mlx_hook(t_win *wind)
// {
// 	// mlx_hook(wind->mlx_ptr, KEYPRESS, 0, key_hook, wind);
// 	// mlx_hook(wind->mlx_ptr, MOTIONNOTIFY, 0, mouse_hook, wind);
// 	// mlx_hook(wind->mlx_ptr, BUTTONPRESS, 0, scroll_hook, wind);
// 	mlx_hook(wind->mlx_ptr, DESTROYNOTIFY, 0, exit_window, wind);
// }

int	read_key(int press_key, t_all *all)
{
	if (press_key == ESC)
		exit_window(&all->wind);
	else if (press_key == ARROW_LEFT)
	{
		printf("ARROW_LEFT\n");
		all->mv.x -= 0.5;
	}
	else if (press_key == ARROW_RIGHT)
		printf("ARROW_RIGHT\n");
	else if (press_key == ARROW_UP)
		printf("ARROW_UP\n");
	else if (press_key == ARROW_DOWN)
		printf("ARROW_DOWN\n");
	else if (press_key == CTRL)
		printf("CTRL\n");
	return (0);
}

// AMB DESTROY WIDOW
int	exit_window(t_win *wind)
{
	if (wind)
		mlx_destroy_window (wind->mlx_ptr, wind->win_ptr);//DONA ERROR, SEGV
	exit(EXIT_SUCCESS);
}
