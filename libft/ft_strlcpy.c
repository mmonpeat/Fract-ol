/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:58:06 by mmonpeat          #+#    #+#             */
/*   Updated: 2022/10/01 19:12:56 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	size;
	size_t	i;

	size = 0;
	while (src[size] != '\0')
		size++;
	if (dstsize == 0)
		return (size);
	i = 0;
	while (((char *)src)[i] && i < dstsize - 1)
	{
		dst[i] = ((char *)src)[i];
		i++;
	}
	dst[i] = '\0';
	return (size);
}
