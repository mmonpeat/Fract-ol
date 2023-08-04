/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:33:56 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/04 18:10:47 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	pastel_colors(int pos)
{
	if (pos == 0)
		return (0xFFDDC1); // Rosa suau
	if (pos == 1)
		return (0xFFE4B5); // Blau clar
	if (pos == 2)
		return (0xE0EEE0); // Verd menta
	if (pos == 3)
		return (0xE6E6FA); // Lila clar
	if (pos == 4)
		return (0xFFDAB9); // Taronja suau
	if (pos == 5)
		return (0xFFE4E1); // Rosat clar
	if (pos == 6)
		return (0xADD8E6); // Blau cel
	if (pos == 7)
		return (0xF0E68C); // Groc pàlid
	if (pos == 8)
		return (0xB0E57C); // Verd pastel
	if (pos == 9)
		return (0xE5A4CB); // Lila pastel
}

int psychedelic_colors(int pos)
{
	if (pos == 0)
		return 0xFF00FF; // Magenta
	if (pos == 1)
		return 0x00FF00; // Verd
	if (pos == 2)
		return 0xFFFF00; // Groc
	if (pos == 3)
		return 0x0000FF; // Blau
	if (pos == 4)
		return 0xFF0000; // Vermell
	if (pos == 5)
		return 0x00FFFF; // Cian
	if (pos == 6)
		return 0xFFA500; // Taronja
	if (pos == 7)
		return 0x800080; // Lila
	if (pos == 8)
		return 0xFF1493; // Rosa
	if (pos == 9)
		return 0x00CED1; // Turquesa
	return 0x000000; // Color predeterminat (negre)
}
