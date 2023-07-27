/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:50:31 by mmonpeat          #+#    #+#             */
/*   Updated: 2022/10/12 17:41:22 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
	{
		write (fd, "-", 1);
		write (fd, "2147483648", 10);
		return ;
	}
	else if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
		ft_putnbr_fd (n, fd);
	}
	else if (n < 10)
	{
		digit = n + '0';
		write(fd, &digit, 1);
	}
	else if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
}
