/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:20:21 by mmonpeat          #+#    #+#             */
/*   Updated: 2022/10/03 15:46:04 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;
	size_t	i;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	a = ft_strlen(dst);
	b = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && a < dstsize - 1)
	{
		dst[a] = src[i];
		a++;
		i++;
	}
	if (dstsize != 0 && a <= dstsize)
		dst[a] = '\0';
	return (b + ft_strlen(src));
}
