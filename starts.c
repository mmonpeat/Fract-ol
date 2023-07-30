/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:30:31 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/29 17:08:22 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	start_all(t_all *all)
{
	// t_img		img;
	// t_win		wind;
	// t_cplane	fractal;
	// t_mv		mv;

	// all->fractal = (t_cplane *)malloc(sizeof(t_cplane));
	// all->img = (t_img *)malloc(sizeof(t_img));
	// all->mv = (t_mv *)malloc(sizeof(t_mv));
	// all->wind = malloc(sizeof(t_win));
	// all->img = malloc(sizeof(t_img));
	if (new_program(W, H, "Fractal", &all->wind) == 0)
		return ;
	start_fractal(&all->fractal);
	if (new_img(W, H, &all->img, all->wind.mlx_ptr) == 0)
		return ;
	start_moves(&all->mv);
	// all->fractal = &fractal;
	// all->img = &img;
	// printf("hola\n");
	// all->wind = wind;
	// all->mv = &mv;
}

void	start_fractal(t_cplane *fractal)
{
	fractal->row = -1;
	fractal->col = -1;
	fractal->c_im = 0;
	fractal->c_re = 0;
	fractal->iter = 0;
	fractal->x_s = 0;
	fractal->x_e = 0;
	fractal->y_s = 0;
	fractal->y_e = 0;
}

void	start_moves(t_mv *mv)
{
	mv->x = 0.0;
	mv->y = 0.0;
	mv->z = 0.0; //pq 1?
}