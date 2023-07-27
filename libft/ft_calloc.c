/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:15:48 by mmonpeat          #+#    #+#             */
/*   Updated: 2022/10/01 19:32:31 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*o;

	i = 0;
	o = malloc(count * size);
	if (!o)
		return (NULL);
	while (i < (count * size))
	{
		o[i] = '\0';
		i++;
	}
	return (o);
}
