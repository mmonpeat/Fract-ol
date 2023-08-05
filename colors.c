/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:33:56 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/05 13:26:02 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	pastel_colors(int pos)
{
	static int	pastel[11] = {0xFFDDC1, 0xFFE4B5, 0xE0EEE0, 0xE6E6FA, \
		0xFFDAB9, 0xFFE4E1, 0xADD8E6, 0xF0E68C, 0xB0E57C, 0xE5A4CB, 0};

	return (pastel[pos]);
}

int	psychedelic_colors(int pos)
{
	static int	pastel[11] = {0x800080, 0xFFFF00, 0xFF00FF, 0x0000FF, \
		0xFF0000, 0x00FFFF, 0xFFA500, 0x00FF00, 0xFF1493, 0x00CED1, 0};

	return (pastel[pos]);
}

int	psychedelic_colors2(int pos)
{
	static int	pastel[11] = {0xFF1493, 0x00CED1, 0xFF00FF, 0x0000FF, \
		0xFF0000, 0x00FFFF, 0xFFA500, 0x00FF00, 0x800080, 0xFFFF00, 0};

	return (pastel[pos]);
}

int	bluegreen_colors(int pos)
{
	static int	pastel[11] = {0x00BFFF, 0x1E90FF, 0x007FFF, 0x20B2AA, \
		0x00FF7F, 0x32CD32, 0x7FFF00, 0xADFF2F, 0x9ACD32, 0x006400, 0};

	return (pastel[pos]);
}

int	red_colors(int pos)
{
	static int	pastel[11] = {0xDC143C, 0xB22222, 0xFF0000, 0xFF4500, \
		0xFF6347, 0xFF8C00, 0xFFA07A, 0xFF69B4, 0xFF1493, 0x8B0000, 0};

	return (pastel[pos]);
}