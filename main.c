/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:54:34 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/27 19:47:38 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int main()
{
	t_win		wind;
	t_img		img;
	t_cplane	mandel;
	t_all		all;

	wind = new_program(W, H, "holiwis");
	img = new_img(wind.w, wind.h, wind);
	// start_all(&all);
	mandelbrot(&mandel, &img, wind);
	mlx_put_image_to_window(wind.mlx_ptr, wind.win_ptr, img.img_ptr, 0, 0);
	printf("hola4\n");
	mlx_loop(wind.mlx_ptr);
	mlx_hook(wind.win_ptr, 17, 0, exit_window, &img);
	return (0);
}
