/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_needs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:54:27 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/29 17:07:04 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

// int	new_program(int w, int h, char *str, t_all *all)
// {
// 	(*all)->wind->mlx_ptr = mlx_init();
// 	(*all)->wind->mlx_ptr = mlx_new_window((*all)->wind->mlx_ptr, w, h, str);
// 	if (!(*all)->wind->mlx_ptr)
// 	{
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	return (1);
// }

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

// t_img	new_img(int w, int h, t_win window)
// {
// 	t_img	image;

// 	image.win = window;
// 	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
// 	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
// 			&(image.line_len), &(image.endian));
// 	image.w = w;
// 	image.h = h;
// 	return (image);
// }

// int	new_img(int w, int h, t_all **all)
// {
// 	(*all)->img->img_ptr = mlx_new_image((*all)->wind->mlx_ptr, w, h);
// 	if (!(*all)->img->img_ptr)
// 	{
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	(*all)->img->addr = mlx_get_data_addr((*all)->img->img_ptr, 
// 			&((*all)->img->bpp), &((*all)->img->line_len), 
// 			&((*all)->img->endian));
// 	(*all)->img->w = w;
// 	(*all)->img->h = h;
// 	return (1);
// }

void	my_put_pixel_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img->w && y < img->h)
	{
		// printf("hola\n");
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *) dst = color;
		//printf("es aqui el segfoult?\n");
	}
}

// AMB DESTROY WIDOW
int	exit_window(t_win *window)
{
	if (window)
		mlx_destroy_window (window->mlx_ptr, window->win_ptr);
	exit(EXIT_SUCCESS);
}
