/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:30:31 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/04 18:52:42 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	start_all(t_all *all)
{
	if (new_program(W, H, "Fractal", &all->wind) == 0)
		return ;
	start_fractal(&all->fractal);
	if (new_img(W, H, &all->img, all->wind.mlx_ptr) == 0)
		return ;
	start_moves(&all->mv);
}

void	start_fractal(t_cplane *fractal)
{
	fractal->row = -1;
	fractal->col = -1;
	fractal->im = 0;
	fractal->re = 0;
	fractal->i = 0;
	fractal->x = 0;
	fractal->x_c = 0;
	fractal->y = 0;
	fractal->y_c = 0;
}

void	start_moves(t_mv *mv)
{
	mv->x = 0.0;
	mv->y = 0.0;
	mv->z = 1.0;
	mv->i = 10;
	mv->stop = 0;
	mv->col = pastel_colors;
}
