/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:18:23 by mmonpeat          #+#    #+#             */
/*   Updated: 2022/10/13 15:54:33 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*save;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len > len_s - start)
		len = len_s - start;
	if (start >= len_s)
	{
		save = (char *)malloc(1);
		if (!save)
			return (NULL);
		save[0] = '\0';
		return (save);
	}
	save = (char *)malloc(sizeof(char) * (len + 1));
	if (!save)
		return (NULL);
	while (start--)
		s++;
	ft_strlcpy(save, s, len + 1);
	return (save);
}
