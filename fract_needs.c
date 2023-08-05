/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_needs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:58:27 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/05 15:07:45 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

//dos func de colors
//les de zoom tmb aqui

int	my_col(int i, int ctrl_i, int (*col)(int))
{
	int	color;
	int	iter;

	iter = ctrl_i / 10;
	if (i < iter)
	{
		// printf("i: %i && ctrl_i: %i && iter: %i\n", i, ctrl_i, iter);
		color = ft_get_gradient(0, col(0), iter, i);
	}
	else if (i < iter * 2)
	{
		// printf("i: %i && ctrl_i: %i && iter: %i\n", i, ctrl_i, iter);
		color = ft_get_gradient(col(0), col(1), iter, i - iter);
	}
	else if (i < iter * 3)
	{
		// printf("i: %i && ctrl_i: %i && iter: %i\n", i, ctrl_i, iter);
		color = ft_get_gradient(col(1), col(2), iter, i - (iter * 2));
	}
	else if (i < iter * 4)
	{
		// printf("i: %i && ctrl_i: %i && iter: %i\n", i, ctrl_i, iter);
		color = ft_get_gradient(col(2), col(3), iter, i - (iter * 3));
	}
	else if (i < iter * 5)
	{
		// printf("i: %i && ctrl_i: %i && iter: %i\n", i, ctrl_i, iter);
		color = ft_get_gradient(col(3), col(4), iter, i - (iter * 4));
	}
	else if (i < iter * 6)
	{
		// printf("i: %i && ctrl_i: %i && iter: %i\n", i, ctrl_i, iter);
		color = ft_get_gradient(col(4), col(5), iter, i - (iter * 5));
	}
	else if (i < iter * 7)
	{
		// printf("i: %i && ctrl_i: %i && iter: %i\n", i, ctrl_i, iter);
		color = ft_get_gradient(col(5), col(6), iter, i - (iter * 6));
	}
	else if (i < iter * 8)
	{
		// printf("i: %i && ctrl_i: %i && iter: %i\n", i, ctrl_i, iter);
		color = ft_get_gradient(col(6), col(7), iter, i - (iter * 7));
	}
	else if (i < iter * 9)
	{
		// printf("i: %i && ctrl_i: %i && iter: %i\n", i, ctrl_i, iter);
		color = ft_get_gradient(col(7), col(8), iter, i - (iter * 8));
	}
	else if (i < ctrl_i - 1)
	{
		// printf("i: %i && ctrl_i: %i && iter: %i\n", i, ctrl_i, iter);
		color = ft_get_gradient(col(8), col(9), iter, i - (iter * 9));
	}
	else
		color = 0;
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

double	a(double num)
{
	if (num < 0)
		num = -num;
	return (num);
}
