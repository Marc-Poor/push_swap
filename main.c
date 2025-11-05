/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:33:12 by mfaure            #+#    #+#             */
/*   Updated: 2025/11/04 16:40:28 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *calculate_place(t_list *list_a, int new_nbr)
{
	int	place;
	int sure;

	place = 0;
	sure = 0;
	while (list_a->next)
	{
		if (list_a->number == new_nbr)
		{
			place = ft_atoi(list_a->content);
			sure = 1;
		}
		if (list_a->number > new_nbr)
			list_a->content = ft_itoa_base(ft_atoi(list_a->content) + 1, "0123456789");
		if (list_a->number < new_nbr && sure == 0)
			place++;
		list_a = list_a->next;
	}
	return (ft_itoa_base(place, "0123456789"));
}

void binary_converter(t_list *list_a)
{
	while (list_a->next)
	{
		list_a->content = ft_itoa_base(ft_atoi(list_a->content), "01");
		list_a = list_a->next;
	}
}

int	find_biggest(t_list *list_a, int biggest)
{
	while (list_a->next)
	{
		if (ft_strlen(list_a->content) > biggest)
			biggest = ft_strlen(list_a->content);
		list_a = list_a->next;
	}
	return (biggest);
}

void do_pb(t_list **list_a, t_list **list_b)
{
    t_list *tmp;

    if (!*list_a) // nothing to push
        return;

    tmp = *list_a;          // take top of A
    *list_a = (*list_a)->next; // remove it from A

    tmp->next = *list_b;    // push it on top of B
    *list_b = tmp;

    printf("pb\n");
}

void do_pa(t_list **list_a, t_list **list_b)
{
    t_list *tmp;

    if (!*list_b)
        return;

    tmp = *list_b;          // take top of B
    *list_b = (*list_b)->next; // remove it from B

    tmp->next = *list_a;    // push on top of A
    *list_a = tmp;

    printf("pa\n");
}

void do_ra(t_list **list_a)
{
    t_list *first;
    t_list *last;

    if (!*list_a || !(*list_a)->next)
        return;

    first = *list_a;
    *list_a = (*list_a)->next; // second becomes first
    first->next = NULL;

    last = *list_a;
    while (last->next)
        last = last->next;
    last->next = first;

    printf("ra\n");
}

t_list *sort_list(t_list *list_a, t_list *list_b, int i)
{
	char	*str;


	while (list_a->next)
	{
		str = (char *)list_a->content;
		if (ft_strlen(str) - i < 0)
		{
			do_pb(&list_a, &list_b);
			continue;
		}
		if (str[ft_strlen(str) - i - 1] == '0')
			do_pb(&list_a, &list_b);
		if (str[ft_strlen(str) - i - 1] == '1')
			do_ra(&list_a);
		list_a = list_a->next;
	}
	while (*list_b)
	{
		do_pa(&list_a, &list_b);
	}
	return (list_a);
}

void radix_loop(t_list *list_a, t_list *list_b, int biggest)
{
	int i;

	i = 0;
	while (biggest - i > 0)
	{
		list_a = sort_list(list_a, list_b, i);
		i++;
	}
	while (list_a->next)
	{
		printf("%i\n", list_a->number);
		list_a = list_a->next;
	}
}

int	main(int ac, char **av)
{
	int	i;
	t_list *list_a;
	t_list *list_b;

	i = 1;
	list_b = NULL;
	if (ac < 2 || !av || !av[0])
		return (0);
	list_a = ft_lstnew("0", ft_atoi(av[i]));
	while (av[i])
	{
		ft_lstadd_back(&list_a, ft_lstnew(calculate_place(list_a, ft_atoi(av[i])), ft_atoi(av[i])));
		i++;
	}
	binary_converter(list_a);
	i = find_biggest(list_a, 0);
	radix_loop(list_a, list_b, i);
	return (0);
}