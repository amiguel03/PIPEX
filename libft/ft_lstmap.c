/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:16:59 by sergio            #+#    #+#             */
/*   Updated: 2024/01/23 00:19:57 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del_wrapper(void *content)
{
	free(content);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*next_list;
	void	*v;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		v = f(lst->content);
		next_list = ft_lstnew(v);
		if (next_list == NULL)
		{
			del (v);
			ft_lstclear(&new_list, del_wrapper);
			return (NULL);
		}
		ft_lstadd_back(&new_list, next_list);
		lst = lst->next;
	}
	return (new_list);
}
