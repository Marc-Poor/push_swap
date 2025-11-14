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

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (write(1, s, i));
}

void	do_pb(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;

	if (!*list_a)
		return ;
	tmp = *list_a;
	*list_a = (*list_a)->next;
	tmp->next = *list_b;
	*list_b = tmp;
	ft_putstr("pb\n");
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
	ft_putstr("pa\n");
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
	ft_putstr("ra\n");
}

void do_rra(t_list **a) 
{
    t_list *tmp;
    t_list *last;

    if (!*a || !(*a)->next)
		return ;
    tmp = *a;
    while (tmp->next->next)
		tmp = tmp->next;
    last = tmp->next;
    tmp->next = NULL;
    last->next = *a;
    *a = last;
    ft_putstr("rra\n");
}

void do_sa(t_list **a)
{
    t_list *b;

    if (!*a || !(*a)->next)
		return ;
	b = (*a)->next;
    (*a)->next = b->next;
    b->next = *a;
    *a = b;
	ft_putstr("sa\n");
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