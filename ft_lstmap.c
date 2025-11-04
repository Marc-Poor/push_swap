/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:36:55 by mfaure            #+#    #+#             */
/*   Updated: 2025/11/04 11:35:43 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*link;
	void	*tmp;

	new = NULL;
	while (lst && f)
	{
		tmp = f(lst->content);
		link = ft_lstnew(tmp);
		if (!link)
		{
			del(tmp);
			ft_lstclear(&new, del);
			free(link);
			return (NULL);
		}
		ft_lstadd_back(&new, link);
		lst = lst->next;
	}
	return (new);
}
