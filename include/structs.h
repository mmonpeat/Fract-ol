/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:29:04 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/30 19:06:37 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL

# include <mlx.h>

//MACROS
# define W 1280
# define H 1080

//teclat
# define ESC 53				//key escape
# define W 13				// 'W' key
# define A 0				// 'A' key
# define S 1				// 'S' key
# define D 2				// 'D' key
# define ARROW_UP 126		// Arrow up key
# define ARROW_DOWN 125		// Arrow down key
# define ARROW_LEFT 123		// Arrow left key
# define ARROW_RIGHT 124	// Arrow right key
# define CTRL 256			// Control key
# define CMD 259	// Command key (Windows key on Windows, Command key on macOS)

//mouse
# define MOUSE_LEFT_BUTTON 1	// Left mouse button
# define MOUSE_RIGHT_BUTTON 2	// Right mouse button
# define MOUSE_MIDDLE_BUTTON 3	// Middle mouse button
# define MOUSE_X1_BUTTON 4		// Mouse X1 button Zoom in
# define MOUSE_X2_BUTTON 5		// Mouse X2 button Zoom out

# define 

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		w;
	int		h;
}		t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		w;
	int		h;
	int		bpp;//bites_per_pixel
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_complex_plane
{
	t_img				*img_ptr;
	void				(*fractal_function)(struct s_complex_plane *);
	int					iter;
	int					row;
	int					col;
	double				x_s;//tmb serveix per ser els la x de la z i per el zoom
	double				x_e;
	double				y_s;//tmb serveix per ser els la y de la z i per el zoom
	double				y_e;
	double				c_re;//num complex
	double				c_im;//num complex
}			t_cplane;

typedef struct s_moves
{
	double	x;
	double	y;
	double	z;
}		t_mv;

typedef struct s_all
{
	t_win		wind;
	t_img		img;
	t_cplane	fractal;
	t_mv		 mv;
}		t_all;

#endif