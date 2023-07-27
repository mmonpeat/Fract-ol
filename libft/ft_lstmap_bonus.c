/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonpeat <mmonpeat@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:26:40 by mmonpeat          #+#    #+#             */
/*   Updated: 2022/10/27 18:52:47 by mmonpeat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*nod;
	void	*p;

	new = 0;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		p = (f)(lst->content);
		nod = ft_lstnew(p);
		if (!nod)
		{
			ft_lstclear(&new, del);
			free(p);
			return (NULL);
		}
		ft_lstadd_back(&new, nod);
		lst = lst->next;
	}
	return (new);
}
