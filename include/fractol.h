/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:07:40 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/04 18:10:37 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <complex.h> // Inclou la llibreria complex.h per a utilitzar la constant "I"
/*BORRAR ???*/
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "mlx.h"
# include "libft.h"
# include "structs.h"
# include "macros.h"

/*ecollir fraaactals*/
void			menu(int ac);
void			select_function(char *arg, t_all *all);
void			recompile_fractal(t_all *all);

/* mlx Minilibx General */
int				new_program(int w, int h, char *str, t_win *wind);
int				new_img(int w, int h, t_img *img, void *mlx_ptr);
void			my_put_pixel_img(t_img *img, int x, int y, int color);

/* MOVIMENTS */
void			add_mlx_hook(t_all *all);
int				read_key(int press_key, t_all *all);
int				mouse_hook(int x, int y, t_all *all);
int				scroll_hook(int button, int x, int y, t_all *all);
int				exit_window(t_win *wind);

/* fractals */
void			mandelbrot(t_cplane *mand, t_img *img, t_mv *mv, t_win *wind);
void			julia(t_cplane *m, t_img *img, t_mv *mv, t_win *w);
void			ship(t_cplane *m, t_img *img, t_mv *mv, t_win *w);
double			a(double num);
int				my_col(int i, int ctrl_i, int (*col)(int));
int				ft_get_gradient(int start, int end, float len, float pos);
int				pastel_colors(int pos);
int				psychedelic_colors(int pos);

/* inicialitzar */
void			start_all(t_all *all);
void			start_fractal(t_cplane *fractal);
void			start_moves(t_mv *mv);

#endif