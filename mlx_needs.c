/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_needs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:54:27 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/30 18:35:13 by mmonpeat         ###   ########.fr       */
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

// AMB DESTROY WIDOW
int	exit_window(t_win *window)
{
	if (window)
		mlx_destroy_window (window->mlx_ptr, window->win_ptr);
	exit(EXIT_SUCCESS);
}
