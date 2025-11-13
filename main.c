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

void    sort3(t_list *list_a)
{
    int        x;
    int        y;
    int        z;

    x = list_a->number;
    y = list_a->next->number;
    z = list_a->next->next->number;
    if (x > y && y < z && x < z)
        write(1, "sa\n", 3);
    if (x > y && y > z)
        write(1, "sa\nrra\n", 7);
    if (x > y && y < z && x > z)
        write(1, "ra\n", 3);
    if (x < y && y > z && x < z)
        write(1, "sa\nra\n", 6);
    if (x < y && y > z && x > z)
        write(1, "rra\n", 4);
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
	{
		write(2, "Error\n", 6);
		return (0);
	}
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
	{
		if (list_a->next->number < list_a->number)
			write(1, "sa\n", 3);
		return (0);
	}
	if (ac == 4)
	{
		sort3(list_a);
		return 0;
	}
	assign_ranks(list_a);
	binary_converter(list_a);
	i = find_biggest(list_a, 0);
	if (ac == 5 || ac == 6)
		
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