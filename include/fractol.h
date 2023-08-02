/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:07:40 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/02 17:52:07 by mmonpeat         ###   ########.fr       */
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
# include "macros.h"

/* mlx Minilibx General */
int				new_program(int w, int h, char *str, t_win *wind);
int				new_img(int w, int h, t_img *img, void *mlx_ptr);
void			my_put_pixel_img(t_img *img, int x, int y, int color);

/* MOVIMENTS */
// static void		add_mlx_hook(t_win wind);
int				read_key(int press_key, t_all *all);
int				mouse_hook(int x, int y, t_all *all);
// int				scroll_hook(int button, int x, int y, t_all *all);
int				exit_window(t_win *wind);

/* fractals */
void			mandelbrot(t_cplane *mand, t_img *img, t_mv *mv, t_win *wind);
int				my_colors(int i);
int				ft_get_gradient(int start, int end, float len, float pos);

/* inicialitzar */
// void	        menu(int ac);
void			start_all(t_all *all);
void			start_fractal(t_cplane *fractal);
void			start_moves(t_mv *mv);

/**/
/* Complex numbers */
// double _Complex	ipow(double _Complex inum);
// double _Complex	iplus(double _Complex inum1, double _Complex inum2);
// double			norm(double _Complex inum);

#endif