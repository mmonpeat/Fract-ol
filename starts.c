/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:30:31 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/01 13:51:15 by mmonpeat         ###   ########.fr       */
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
	mv->x = 1.5;
	mv->y = 2.0;
	mv->z = 1.0;
}
