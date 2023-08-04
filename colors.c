/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:33:56 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/04 19:16:56 by mmonpeat         ###   ########.fr       */
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
	static int	pastel[11] = {0xFF00FF, 0x00FF00, 0xFFFF00, 0x0000FF, \
		0xFF0000, 0x00FFFF, 0xFFA500, 0x800080, 0xFF1493, 0x00CED1, 0};

	return (pastel[pos]);
}
