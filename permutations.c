/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:24:39 by mfaure            #+#    #+#             */
/*   Updated: 2025/11/13 19:30:11 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pb(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;

	if (!*list_a)
		return ;
	tmp = *list_a;
	*list_a = (*list_a)->next;
	tmp->next = *list_b;
	*list_b = tmp;
	printf("pb\n");
}

void	do_pa(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;

	if (!*list_b)
		return ;
	tmp = *list_b;
	*list_b = (*list_b)->next;
	tmp->next = *list_a;
	*list_a = tmp;
	printf("pa\n");
}

void	do_ra(t_list **list_a)
{
	t_list	*first;
	t_list	*last;

	if (!*list_a || !(*list_a)->next)
		return ;
	first = *list_a;
	*list_a = (*list_a)->next;
	first->next = NULL;
	last = *list_a;
	while (last->next)
		last = last->next;
	last->next = first;
	printf("ra\n");
}

/*
void	do_pa(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;

	if (!*list_b)
		return ;
	tmp = *list_b;// take top of B
	*list_b = (*list_b)->next;// remove it from B
	tmp->next = *list_a;// push on top of A
	*list_a = tmp;
	printf("pa\n");
}

*/