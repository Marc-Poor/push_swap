/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:33:12 by mfaure            #+#    #+#             */
/*   Updated: 2025/11/13 21:44:32 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_ranks(t_list *list)
{
	t_list	*outer;
	t_list	*inner;
	char	*new_content;
	int		rank;

	outer = list;
	while (outer)
	{
		rank = 0;
		inner = list;
		while (inner)
		{
			if (inner->number < outer->number)
				rank++;
			inner = inner->next;
		}
		/* free old content string if allocated previously */
		free(outer->content);
		new_content = ft_itoa_base(rank, "0123456789");
		outer->content = new_content;
		outer = outer->next;
	}
}
// for (t_list *tmp = list_a; tmp; tmp = tmp->next)
//	printf("%d %s\n", tmp->number, (char *)tmp->content);

void push_smallest_two(t_list **a, t_list **b)
{
	int rank;

    while (ft_lstsize(*a) > 3)
    {
        rank = ft_atoi((*a)->content);

        if (rank == 0 || rank == 1)
            do_pb(a, b);
        else
            do_ra(a);
    }
}

void push_back_two(t_list **a, t_list **b)
{
    int top;

	top = ft_atoi((*b)->content);
    if ((top == 0 && ft_lstsize(*b) == 2) | (ft_lstsize(*b) == 1 && top == 1))
    {
        do_pa(a, b);
        do_pa(a, b);
		do_sa(a);
    }
    else
    {
        do_pa(a, b);
        do_pa(a, b);
    }
}

void sort_three(t_list **a)
{
    int x;
    int y;
    int z;

    x = ft_atoi((*a)->content);
    y = ft_atoi((*a)->next->content);
    z = ft_atoi((*a)->next->next->content);
    if (x > y && y < z && x < z)
        do_sa(a);
    else if (x > y && y > z)
        { do_sa(a); do_rra(a); }
    else if (x > y && y < z && x > z)
        do_ra(a);
    else if (x < y && y > z && x < z)
    { 
		do_sa(a); 
		do_ra(a);
	}
    else if (x < y && y > z && x > z)
        do_rra(a);
}

void sort_five(t_list **a, t_list **b)
{
    push_smallest_two(a, b);
	sort_three(a);
    push_back_two(a, b);
}

void	binary_converter(t_list *list_a)
{
	t_list	*tmp;
	char	*old;

	tmp = list_a;
	while (tmp)
	{
		old = tmp->content;
		tmp->content = ft_itoa_base(ft_atoi(old), "01");
		free(old);
		tmp = tmp->next;
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

int	main(int ac, char **av)
{
	int		i;
	t_list	*list_a;
	t_list	*list_b;

	list_b = NULL;
	if (ac < 3 || !av || !av[0])
		return (0);
	if (!error_value(av, 1, 0) || !compare(av, ac))
		return (write(2, "Error\n", 6));
	if (in_order(av, 2, ac) == 0)
		return (0);
	list_a = NULL;
	i = 1;
	while (av[i])
	{
		ft_lstadd_back(&list_a, ft_lstnew(ft_itoa_base(ft_atoi(av[i]),
					"0123456789"), ft_atoi(av[i])));
		i++;
	}
	if (ac == 3)
		return (write(1, "sa\n", 3));
	if (ac == 4)
	{
		sort_three(&list_a);
		return 0;
	}
	assign_ranks(list_a);
	if (ac == 5 || ac == 6)		
	{
		sort_five(&list_a, &list_b);
		return 0;
	}
	binary_converter(list_a);
	i = find_biggest(list_a, 0);
	radix_loop(&list_a, &list_b, i);
	return (0);
}

/*
char	*calculate_place(t_list *list_a, int new_nbr)
{
	int		place;
	t_list	*tmp;

	place = 0;
	tmp = list_a;
	while (tmp)
	{
		if (tmp->number < new_nbr)
			place++;
		tmp = tmp->next;
	}
	return (ft_itoa_base(place, "0123456789"));
}

char	*calculate_place(t_list *list_a, int new_nbr)
{
	int	place;

	place = 0;
	while (list_a->next)
	{
		if (list_a->number > new_nbr)
			list_a->content = ft_itoa_base(ft_atoi(list_a->content) + 1,
					"0123456789");
		if (list_a->number < new_nbr == 0)
			place++;
		list_a = list_a->next;
	}
	return (ft_itoa_base(place, "0123456789"));
}

*/