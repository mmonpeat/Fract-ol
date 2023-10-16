/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:50:21 by mmonpeat          #+#    #+#             */
/*   Updated: 2022/10/12 19:54:37 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split(char const *s, char c);
static int	ft_free(char **arr);
static int	ft_count(char *str, char c);
static int	ft_lenword(char *str, char c, int i);
static int	ft_fill_split(char **arr, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	int		num_par;
	char	**arr;

	num_par = ft_count((char *)s, c);
	arr = (char **)malloc(sizeof(char *) * (num_par + 1));
	if (!arr)
		return (NULL);
	if (num_par)
	{
		if (ft_fill_split(arr, s, c) == 0)
			return (NULL);
	}
	else
		arr[0] = NULL;
	return (arr);
}

static int	ft_fill_split(char **arr, char const *s, char c)
{
	int	i;
	int	n;
	int	len;

	i = 0;
	n = 0;
	while (s[i] && n < ft_count((char *)s, c))
	{
		if (s[i] != c)
		{
			len = ft_lenword((char *)s, c, i);
			arr[n] = ft_substr(s, i, len);
			if (!arr[n])
				return (ft_free(arr));
			n++;
			i += ft_lenword((char *)s, c, i);
		}	
		else
			i++;
	}
	arr[n] = NULL;
	return (1);
}

static int	ft_count(char *str, char c)
{
	int		i;
	int		par;

	i = 0;
	par = 0;
	while (str[i])
	{
		if (str[i] == c && i != 0 && str[i - 1] != c && str[i - 1])
			par++;
		i++;
	}
	if (str[i] == '\0' && i != 0 && str[i - 1] != c && str[i - 1])
		par++;
	return (par);
}

static int	ft_lenword(char *str, char c, int i)
{
	int		cont;

	cont = 0;
	while (str[i] != c && str[i])
	{
		cont++;
		i++;
	}
	return (cont);
}

static int	ft_free(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free (arr);
	return (0);
}
