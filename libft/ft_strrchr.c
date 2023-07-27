/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:41:58 by mmonpeat          #+#    #+#             */
/*   Updated: 2022/10/01 19:14:43 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*start;

	start = (unsigned char *)s - 1;
	while (*((unsigned char *)s) != '\0')
		s++;
	if (!(unsigned char)c)
		return ((char *)s);
	s--;
	while (((unsigned char *)s) != start)
	{
		if (*((unsigned char *)s) == (unsigned char)c)
			return ((char *)s);
		s--;
	}
	return (0);
}
