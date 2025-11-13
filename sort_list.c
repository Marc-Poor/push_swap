/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:24:05 by mfaure            #+#    #+#             */
/*   Updated: 2025/11/13 19:33:05 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_list **list_a, t_list **list_b, int i)
{
	char	*str;
	int		size;
	int		len;

	size = ft_lstsize(*list_a);
	while (size--)
	{
		str = (char *)(*list_a)->content;
		len = ft_strlen(str);
		if (len - i - 1 < 0 || str[len - i - 1] == '0')
			do_pb(list_a, list_b);
		else
		{
			do_ra(list_a);
		}
	}
	while (*list_b)
		do_pa(list_a, list_b);
}

void	radix_loop(t_list **list_a, t_list **list_b, int biggest)
{
	int	i;

	i = 0;
	while (biggest - i > 0)
	{
		sort_list(list_a, list_b, i);
		i++;
	}
}

// for (t_list *tmp = *list_a; tmp; tmp = tmp->next)
//	printf("%d\n", tmp->number);

/*

void	sort_list(t_list **list_a, t_list **list_b, int i)
{
	int		size;
	char	*str;
	int		len;

	size = ft_lstsize(*list_a);
	while (size--)
	{
		str = (char *)(*list_a)->content;
		len = ft_strlen(str);
		if (len - i - 1 < 0 || str[len - i - 1] == '0')
			do_pb(list_a, list_b);
		else
			do_ra(list_a);
	}
	while (*list_b)
		do_pa(list_a, list_b);
}

	void	radix_loop(t_list **list_a, t_list **list_b, int biggest)
{
	for (int i = 0; i < biggest; i++)
		sort_list(list_a, list_b, i);
	// print sorted stack for debug
	for (t_list *tmp = *list_a; tmp; tmp = tmp->next)
		printf("%d\n", tmp->number);
}
	*/