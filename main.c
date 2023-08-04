/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:54:34 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/08/04 16:04:56 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	main(int ac, char **av)
{
	t_all		all;

	if (ac != 2)
		menu(ac);
	else
	{
		if (ft_strncmp(av[1], "mandelbrot", 10) != 0 
			&& (ft_strncmp(av[1], "julia", 5) != 0)
			&& (ft_strncmp(av[1], "ship", 5) != 0))
		{
			menu(ac = 1);
			return (0);
		}
		start_all(&all);
		all.fractal.name = av[1];
		select_function(all.fractal.name, &all);
		add_mlx_hook(&all);
		mlx_loop(all.wind.mlx_ptr);
	}
}

void	menu(int ac)
{
	if (ac == 1)
	{
		write(2, "Escriu un fractal:\n", 19);
		write(2, "1) mandelbrot\n", 14);
		write(2, "2) julia\n", 10);
		write(2, "3) ship\n", 9);
	}
	else if (ac > 2)
	{
		write(2, "Masses arguments!", 17);
		write(2, "Escriu un fractal:\n", 19);
		write(2, "1) mandelbrot\n", 14);
		write(2, "2) julia\n", 10);
		write(2, "3) ship\n", 9);
	}
}

void	select_function(char *arg, t_all *all)
{
	if (ft_strncmp(arg, "mandelbrot", 1) == 0)
		mandelbrot(&all->fractal, &all->img, &all->mv, &all->wind);
	else if (ft_strncmp(arg, "julia", 5) == 0)
		julia(&all->fractal, &all->img, &all->mv, &all->wind);
	else if (ft_strncmp(arg, "ship", 4) == 0)
		ship(&all->fractal, &all->img, &all->mv, &all->wind);
}

void	recompile_fractal(t_all *all)
{
	if (ft_strncmp(all->fractal.name, "mandelbrot", 10) == 0)
		mandelbrot(&all->fractal, &all->img, &all->mv, &all->wind);
	else if (ft_strncmp(all->fractal.name, "julia", 5) == 0)
		julia(&all->fractal, &all->img, &all->mv, &all->wind);
	else if (ft_strncmp(all->fractal.name, "ship", 4) == 0)
		ship(&all->fractal, &all->img, &all->mv, &all->wind);
}
