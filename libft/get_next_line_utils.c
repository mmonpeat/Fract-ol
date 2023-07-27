/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:38:27 by mmonpeat          #+#    #+#             */
/*   Updated: 2023/07/18 12:26:10 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// char	*ft_strjoin_free(char *storage, char *buffer)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (!storage)
// 		return (NULL);
// 	str = malloc(sizeof(char) * (ft_strlen(storage) + ft_strlen(buffer)) + 1);
// 	if (!str)
// 		return (ft_free(&storage));
// 	i = -1;
// 	j = 0;
// 	while (storage[++i] != '\0')
// 		str[i] = storage[i];
// 	while (buffer[j] != '\0')
// 		str[i++] = buffer[j++];
// 	str[i] = '\0';
// 	free(storage);
// 	return (str);
// }

// char	*ft_strchr_gnl(char *s, int c)
// {
// 	char	*a;
// 	int		i;

// 	a = (char *)s;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == (unsigned char)c)
// 			return (&a[i]);
// 		i++;
// 	}
// 	if ((unsigned char)c == '\0')
// 		return (&a[i]);
// 	else
// 		return (NULL);
// }
