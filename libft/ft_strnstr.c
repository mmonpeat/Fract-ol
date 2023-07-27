/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:53:46 by mmonpeat          #+#    #+#             */
/*   Updated: 2022/10/01 19:13:52 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (needle[0] == haystack[i])
		{
			j = 0;
			while (needle[j] == haystack[i + j] && (i + j) < len)
			{
				j++;
				if (!needle[j])
					return ((char *)haystack + i);
			}
		}
		i++;
	}
	return (NULL);
}
