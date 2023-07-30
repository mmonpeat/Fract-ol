/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:54:34 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/29 17:07:43 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	main()
{
	t_all		all;
	// t_win		wind;
	// t_cplane	fractal;
	// t_mv		mv;
	start_all(&all);
	// printf("IMG: %d\n", all.img->h);
	mandelbrot(&all.fractal, &all.img, &all.mv);
	// printf("mlx_ptr: %p && win_ptr: %p && img_ptr: %p\n", all.wind->mlx_ptr, all.wind->win_ptr, all.img->img_ptr);
	mlx_put_image_to_window(all.wind.mlx_ptr, all.wind.win_ptr, 
		all.img.img_ptr, 0, 0);
	mlx_loop(all.wind.mlx_ptr);
	// mlx_hook(all.wind.win_ptr, 17, 0, exit_window, all.img);
	
}

// int	main(int ac, char *av)
// {
// 	t_all		all;

// 	if (ac < 2)
// 		write(1, "Has d'introduir almenys un argument ;)\n", 39);
// 	start_all(&all);
// 	show_plane(all);
// 	mandelbrot(all.fractal, all.img, all.wind);
// 	mlx_put_image_to_window(all.wind.mlx_ptr, all.wind.win_ptr, 
// 		all.img->img_ptr, 0, 0);
// 	mlx_loop(all.wind.mlx_ptr);
// 	// mlx_hook(all.wind.win_ptr, 17, 0, exit_window, all.img);
// }