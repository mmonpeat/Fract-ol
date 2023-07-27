/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:38:30 by mmonpeat          #+#    #+#             */
/*   Updated: 2022/10/10 17:00:45 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	aux;
	size_t	aux2;
	char	*s;

	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	aux = 0;
	aux2 = 0;
	while (s1[aux])
	{
		s[aux] = s1[aux];
		aux++;
	}
	while (s2[aux2])
	{
		s[aux] = s2[aux2];
		aux++;
		aux2++;
	}
	s[aux] = '\0';
	return (s);
}
