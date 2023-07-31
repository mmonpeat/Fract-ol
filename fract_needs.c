/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_needs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:58:27 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/31 15:25:16 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

//dos func de colors
//les de zoom tmb aqui

int	my_colors(int i)
{
	int	color;

	if (i < 20)
		color = ft_get_gradient(0, 0xFF0000, 20, i);
	else if (i < 40)
		color = ft_get_gradient(0xFF0000, 0xEE0000, 20, i - 20);
	else if (i < 80)
		color = ft_get_gradient(0xEE0000, 0xDD0000, 40, i - 40);
	else if (i < 99)
		color = ft_get_gradient(0xDD0000, 0xCC0000, 19, i - 80);
	else
		color = 0;
	// if (i < 200)
	// 	color = ft_get_gradient(0, 0xFF0000, 200, i);
	// else if (i < 400)
	// 	color = ft_get_gradient(0xFF0000, 0xEE0000, 200, i - 200);
	// else if (i < 800)
	// 	color = ft_get_gradient(0xEE0000, 0xDD0000, 400, i - 400);
	// else if (i < 990)
	// 	color = ft_get_gradient(0xDD0000, 0xCC0000, 999, i - 800);
	// else
	// 	color = 0;
	// printf("Color: %#.6X\n", color);
	return (color);
}

int	ft_get_gradient(int start, int end, float len, float pos)
{
	float	dif[4];
	int		new[4];

	dif[0] = ((end >> 24) - (start >> 24)) / len;
	dif[1] = (((end >> 16) & 0xFF) - ((start >> 16) & 0xFF)) / len;
	dif[2] = (((end >> 8) & 0xFF) - ((start >> 8) & 0xFF)) / len;
	dif[3] = ((end & 0xFF) - (start & 0xFF)) / len;
	new[0] = (start >> 24) + (pos * dif[0]);
	new[1] = ((start >> 16) & 0xFF) + (pos * dif[1]);
	new[2] = ((start >> 8) & 0xFF) + (pos * dif[2]);
	new[3] = (start & 0xFF) + (pos * dif[3]);
	return ((int)(new[0] << 24) | (int)((new[1] << 16)) | (int)((new[2] << 8)) \
		| (int)(new[3]));
}

// void	ft_zoom()
// {
// 	all->fractol.min_x += (((float)x / 8.0 * (float)(all->fractol.max_x - \
//         all->fractol.min_x)) / (float)all->fractol.width);
//     all->fractol.min_y += (((float)y / 8.0 * (float)(all->fractol.max_y - \
//         all->fractol.min_y)) / (float)all->fractol.height);
//     all->fractol.max_x -= ((((float)all->fractol.width - (float)x) / 8.0 * \
//         (float)(all->fractol.max_x - all->fractol.min_x)) / \
//         (float)all->fractol.width);
//     all->fractol.max_y -= ((((float)all->fractol.height - (float)y) / 8.0 * \
//         (float)(all->fractol.max_y - all->fractol.min_y)) / \
// 		(float)all->fractol.height);
// }