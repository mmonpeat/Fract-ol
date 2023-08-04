/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_needs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:58:27 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/04 14:41:56 by mmonpeat         ###   ########.fr       */
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
		color = ft_get_gradient(0, 0xFFDDC1, ns, i);
	else if (i < iter * 2)
		color = ft_get_gradient(0xFFDDC1, 0xFFE4B5, ns, i - ns);
	else if (i < iter * 3)
		color = ft_get_gradient(0xFFE4B5, 0xE0EEE0, ns, i - ns);
	else if (i < iter * 4)
		color = ft_get_gradient(0xE0EEE0, 0xE6E6FA, ns, i - ns);
	else if (i < iter * 5)
		color = ft_get_gradient(0xE6E6FA, 0xFFDAB9, ns, i - ns);
	else if (i < iter * 6)
		color = ft_get_gradient(0xFFDAB9, 0xFFE4E1, ns, i - ns);
	else if (i < iter * 7)
		color = ft_get_gradient(0xFFE4E1, 0xADD8E6, ns, i - ns);
	else if (i < ctrl_i - 1)
		color = ft_get_gradient(0xADD8E6, 0xF0E68C, ns, i - ns);
	else
		color = 0;
	return (color);
}

/*0xFFDDC1, // Rosa suau
0xFFE4B5, // Blau clar
0xE0EEE0, // Verd menta
0xE6E6FA, // Lila clar
0xFFDAB9, // Taronja suau
0xFFE4E1, // Rosat clar
0xADD8E6, // Blau cel
0xF0E68C  // Groc pàlid*/

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
