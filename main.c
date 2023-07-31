/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:54:34 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/31 19:29:50 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	main(void)
{
	t_all		all;

	start_all(&all);
	mandelbrot(&all.fractal, &all.img, &all.mv);
	mlx_put_image_to_window(all.wind.mlx_ptr, all.wind.win_ptr, 
		all.img.img_ptr, 0, 0);
	mlx_key_hook (all.wind.win_ptr, read_key, &all.img);
	add_mlx_hook(&all.wind);
	mlx_hook(all.wind.win_ptr, 17, 0, exit_window, &all.img);
	mlx_loop(all.wind.mlx_ptr);
}
