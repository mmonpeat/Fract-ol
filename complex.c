/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:43:56 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/23 15:23:42 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

// Funció que retorna el quadrat d'un nombre complex
double _Complex	ipow(double _Complex inum)
{
	double _Complex	res;

	res = pow(creal(inum), 2) - pow(cimag(inum), 2) + I * \
			(2 * creal(inum) * cimag(inum));
	return (res);
}

// Funció que retorna la suma de dos nombres complexos
double _Complex	iplus(double _Complex inum1, double _Complex inum2)
{
	double _Complex	inum;

	inum = inum1 + inum2;
	return (inum);
}

// Funció que retorna la norma (magnitud) d'un nombre complex
double	norm(double _Complex inum)
{
	return (cabs(inum));
}