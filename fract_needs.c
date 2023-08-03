/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_needs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:58:27 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/03 16:47:26 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

//dos func de colors
//les de zoom tmb aqui

int	my_colors(int i, int ctrl_i)
{
	int	color;
	int	ns;
	int	iter;

	ns = i % 8;
	iter = ctrl_i / 8;
	if (i < iter)
		color = ft_get_gradient(0, 0xFF0000, ns, i);
	else if (i < iter * 2)
		color = ft_get_gradient(0xFF0000, 0xEE0000, ns, i - ns);
	else if (i < iter * 2)
		color = ft_get_gradient(0xEE0000, 0xDD0000, ns, i - ns);
	else if (i < iter * 2)
		color = ft_get_gradient(0xEE0000, 0xCC0000, ns, i - ns);
	else if (i < iter * 2)
		color = ft_get_gradient(0xEE0000, 0xBB0000, ns, i - ns);
	else if (i < iter * 2)
		color = ft_get_gradient(0xEE0000, 0xAA0000, ns, i - ns);
	else if (i < iter * 2)
		color = ft_get_gradient(0xEE0000, 0x990000, ns, i - ns);
	else if (i < ctrl_i - 1)
		color = ft_get_gradient(0xDD0000, 0x880000, ns, i - ns);
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