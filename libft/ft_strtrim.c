/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:21:37 by mmonpeat          #+#    #+#             */
/*   Updated: 2022/10/10 16:54:00 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	if (!*set || !*s1)
		return (ft_strdup(s1));
	start = 0;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end]) && end > start)
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (end >= start)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
