/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:52:58 by mmonpeat          #+#    #+#             */
/*   Updated: 2022/10/10 15:20:25 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long int n);

char	*ft_itoa(int n)
{
	char		*m;
	long int	num;
	int			size;

	num = n;
	size = len(num);
	m = (char *)malloc(sizeof(char) * (size + 1));
	if (!m)
		return (NULL);
	if (num == 0)
		m[0] = '0';
	if (num < 0)
	{
		num = -num;
		m[0] = '-';
	}
	m[size] = '\0';
	while (num > 0)
	{
		m[--size] = num % 10 + '0';
		num = num / 10;
	}
	return (m);
}

static int	len(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
