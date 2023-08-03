/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:54:34 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/03 14:55:43 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	main(void)
{
	t_all		all;

	start_all(&all);
	mandelbrot(&all.fractal, &all.img, &all.mv, &all.wind);
	// julia(&all.fractal, &all.img, &all.mv, &all.wind);
	// add_mlx_hook(all.wind);
	mlx_hook(all.wind.win_ptr, KEYPRESS, 0, read_key, &all);
	// mlx_hook(all.wind.win_ptr, MOTIONNOTIFY, 0, mouse_hook, &all);
	mlx_hook(all.wind.win_ptr, BUTTONPRESS, 0, scroll_hook, &all);
	mlx_loop(all.wind.mlx_ptr);
}

// void	menu(int ac)
// {
// 	if (ac == 1)
// 	{
// 		write(2, "Escull un fractal:\n", 19);
// 		write(2, "1) Mandelbrot\n", 14);
// 		write(2, "2) Julia\n", 10);
// 		write(2, "3) Ship\n", 9);
// 	}
// 	else if (ac != 2)
// 	{
// 		write(2, "Massa arguments!", 16);
// 		write(2, "Escull un fractal:\n", 19);
// 		write(2, "1) Mandelbrot\n", 14);
// 		write(2, "2) Julia\n", 10);
// 		write(2, "3) Ship\n", 9);
// 	}
// }
