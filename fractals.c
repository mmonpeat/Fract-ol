/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:42:14 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/01 15:59:34 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	mandelbrot(t_cplane *m, t_img *img, t_mv *mv, t_win *w)
{
	double	tmp;

	tmp = 0;
	while (++m->row < img->h)
	{
		m->col = -1;
		while (++m->col < img->w)
		{
			m->c_re = (m->col - img->w / mv->x) * (3 / mv->z) / img->w;
			m->c_im = (m->row - img->h / mv->y) * (3 / mv->z) / img->h;
			m->iter = 0;
			m->x_s = 0;
			m->y_s = 0;
			while (m->iter < mv->ctrl_iter && ((m->x_s * m->x_s) 
					+ (m->y_s * m->y_s) <= 4))
			{
				tmp = (m->x_s * m->x_s) - (m->y_s * m->y_s) + m->c_re;
				m->y_s = 2 * m->x_s * m->y_s + m->c_im;
				m->x_s = tmp;
				m->iter++;
			}
			my_put_pixel_img(img, m->col, m->row, my_colors(m->iter));
		}
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, img->img_ptr, mv->x, mv->y);
}
