/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:42:14 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/02 18:00:16 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

//  	mlx_clear_window(w->mlx_ptr, w->win_ptr);
void	mandelbrot(t_cplane *m, t_img *img, t_mv *mv, t_win *w)
{
	double	tmp;

	tmp = 0;
	m->row = -1;
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	while (++m->row < img->h)
	{
		m->col = -1;
		while (++m->col < img->w)
		{
			m->c_re = (m->col - img->w / 1.5 + mv->x) * 3.0 / (img->w * mv->z);
			m->c_im = (m->row - img->h / 2.0 + mv->y) * 3.0 / (img->h * mv->z);
			m->iter = 0;
			m->x = 0;
			m->y = 0;
			while (m->iter < mv->ctrl_i && ((m->x * m->x) + (m->y * m->y) <= 4))
			{
				tmp = (m->x * m->x) - (m->y * m->y) + m->c_re;
				m->y = 2 * m->x * m->y + m->c_im;
				m->x = tmp;
				m->iter++;
			}
			my_put_pixel_img(img, m->col, m->row, my_colors(m->iter));
		}
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, img->img_ptr, 0, 0);
}
