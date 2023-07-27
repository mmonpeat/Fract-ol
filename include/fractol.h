/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:07:40 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/27 16:34:34 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <complex.h> // Inclou la llibreria complex.h per a utilitzar la constant "I"
/*BORRAR ???*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
# include "mlx.h"
# include "libft.h"
# include "structs.h"

/* mlx Minilibx General */
t_win			new_program(int w, int h, char *str);
t_img			new_img(int w, int h, t_win window);
void			my_put_pixel_img(t_img *img, int x, int y, int color);
int				exit_window(t_win *window);

/* fractals */
void			mandelbrot(t_cplane *mand, t_img *img, t_win win);
int				my_colors(int i);
int				ft_get_gradient(int start, int end, float len, float pos);


/* Complex numbers */
double _Complex	ipow(double _Complex inum);
double _Complex	iplus(double _Complex inum1, double _Complex inum2);
double			norm(double _Complex inum);

#endif