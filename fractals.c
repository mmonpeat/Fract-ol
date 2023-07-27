/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:42:14 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/27 18:41:53 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

void	mandelbrot(t_cplane *mand, t_img *img, t_win win)
{
	double	tmp;
	double	x = 2.0;
	double	y = 1.9;
	double	z = 2.0;

	(void)win;
	tmp = 0;
	printf("mandebrot\n");
	while (++mand->row < img->h)
	{
		mand->col = -1;
		while (++mand->col < img->w)
		{
			mand->c_re = (mand->col - img->w / x) * z / img->w;//x
			mand->c_im = (mand->row - img->h / y) * z / img->h;//y
			mand->iter = 0;
			mand->x_s = 0;
			mand->y_s = 0;
			while (mand->iter < 100 && ((mand->x_s * mand->x_s) 
					+ (mand->y_s * mand->y_s) <= 4))
			{
				tmp = (mand->x_s * mand->x_s) - (mand->y_s * mand->y_s) 
					+ mand->c_re;
				mand->y_s = 2 * mand->x_s * mand->y_s + mand->c_im;
				mand->x_s = tmp;
				mand->iter++;
			}
			my_put_pixel_img(img, mand->col, mand->row, my_colors(mand->iter));
		}
	}
}
