/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:42:14 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/03 17:46:55 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	mandelbrot(t_cplane *m, t_img *img, t_mv *mv, t_win *w)
{
	double	tmp;

	tmp = 0;
	m->row = -1;
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	while (++m->row < img->h)
	{
		m->col = -1;
		m->im = (m->row - img->h / 2.0 + mv->y) * 3.0 / (img->h * mv->z);
		while (++m->col < img->w)
		{
			m->re = (m->col - img->w / 1.5 + mv->x) * 3.0 / (img->w * mv->z);
			m->i = -1;
			m->x = 0;
			m->y = 0;
			while (m->i++ < mv->i && ((m->x * m->x) + (m->y * m->y) <= 4))
			{
				tmp = (m->x * m->x) - (m->y * m->y) + m->re;
				m->y = 2 * m->x * m->y + m->im;
				m->x = tmp;
			}
			my_put_pixel_img(img, m->col, m->row, my_colors(m->i, mv->i));
		}
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, img->img_ptr, 0, 0);
}

/*mandelbrot pero la c canvia amb el ratoli i la z es per cada pixel*/
void	julia(t_cplane *m, t_img *img, t_mv *mv, t_win *w)
{
	double	tmp;

	tmp = 0;
	m->row = -1;
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	while (++m->row < img->h)
	{
		m->col = -1;
		m->y = (m->row - img->h / 2.0 + mv->y) * 3.0 / (img->h * mv->z);
		while (++m->col < img->w)
		{
			m->x = (m->col - img->w / 1.5 + mv->x) * 3.0 / (img->w * mv->z);
			m->re = -0.7269;
			m->im = 0.1889;
			m->i = -1;
			while (m->i++ < mv->i && ((m->x * m->x) + (m->y * m->y) <= 4 || 
					m->i < 1))
			{
				tmp = (m->x * m->x) - (m->y * m->y) + m->re;
				m->y = 2 * m->x * m->y + m->im;
				m->x = tmp;
			}
			my_put_pixel_img(img, m->col, m->row, my_colors(m->i, mv->i));
		}
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, img->img_ptr, 0, 0);
}

/*mandelbrot pero amb la ce en valor absolut*/
void	ship(t_cplane *m, t_img *img, t_mv *mv, t_win *w)
{
	double	tmp;

	tmp = 0;
	m->row = -1;
	mlx_clear_window(w->mlx_ptr, w->win_ptr);
	while (++m->row < img->h)
	{
		m->col = -1;
		m->im = (m->row - img->h / 2.0 + mv->y) * 3.0 / (img->h * mv->z);
		while (++m->col < img->w)
		{
			m->re = (m->col - img->w / 1.5 + mv->x) * 3.0 / (img->w * mv->z);
			m->i = -1;
			m->x = 0;
			m->y = 0;
			while (m->i++ < mv->i && ((m->x * m->x) + (m->y * m->y) <= 4))
			{
				tmp = (m->x * m->x) - (m->y * m->y) + m->re;
				m->y = a(2 * m->x * m->y + m->im);
				m->x = a(tmp);
			}
			my_put_pixel_img(img, m->col, m->row, my_colors(m->i, mv->i));
		}
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, img->img_ptr, 0, 0);
}
