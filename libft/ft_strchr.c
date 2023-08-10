/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:48:44 by mmonpeat          #+#    #+#             */
/*   Updated: 2022/10/01 19:10:54 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!(unsigned char)c)
		return ((char *)s + ft_strlen(s));
	while (*((unsigned char *)s) != '\0')
	{
		if (*((unsigned char *)s) == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}
