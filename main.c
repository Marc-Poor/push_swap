/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:33:12 by mfaure            #+#    #+#             */
/*   Updated: 2025/11/05 18:53:11 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*calculate_place(t_list *list_a, int new_nbr)
{
	int	place;

	place = 0;
	t_list *tmp = list_a;
	while (tmp)
	{
	    if (tmp->number < new_nbr)
            place++;
		tmp = tmp->next;
	}
	return (ft_itoa_base(place, "0123456789"));
}

void	binary_converter(t_list *list_a)
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
	tmp = *list_b;// take top of B
	*list_b = (*list_b)->next;// remove it from B
	tmp->next = *list_a;// push on top of A
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
	*list_a = (*list_a)->next; // second becomes first
	first->next = NULL;
	last = *list_a;
	while (last->next)
		last = last->next;
	last->next = first;
	printf("ra\n");
}

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
	for (t_list *tmp = *list_a; tmp; tmp = tmp->next)
		printf("%d\n", tmp->number);
}

int	error_value(char **av, int y, int x)
{
	while (av[y] != NULL)
	{
		x = 0;
		while (av[y][x] != '\0')
		{
			if (!isdigit(av[y][x]))
				return (0);
			x++;
		}
		if (ft_strlen(av[y]) == 10 && ft_atoi(&av[y][9]) > '7')
			return (0);
		y++;
	}
	return (1);
}

int	compare(char **av, int ac)
{
	int	nb;
	int	compare;

	if (ac < 3)
		return (0);
	nb = 2;
	compare = 1;
	while (compare < ac - 1)
	{
		if (ft_atoi(av[compare]) == ft_atoi(av[nb]))
			return (0);
		nb++;
		if (nb >= ac)
		{
			compare++;
			nb = compare + 1;
		}
	}
	return (1);
}

int	in_order(char **av, int i, int ac)
{
	int count;

	count = i;
	while (av[i])
	{
		if  (ft_atoi(av[i]) > ft_atoi(av[i - 1]))
			count++;
		i++;
	}
	if (count == ac)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	t_list	*list_a;
	t_list	*list_b;

	i = 1;
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
	while (av[i])
	{
	    ft_lstadd_back(&list_a,
	        ft_lstnew(calculate_place(list_a, ft_atoi(av[i])), ft_atoi(av[i]))
	    );
	    i++;
	}
	binary_converter(list_a);
	i = find_biggest(list_a, 0);
	radix_loop(&list_a, &list_b, i);
	return (0);
}

/*

	list_a = ft_lstnew("0", ft_atoi(av[i]));
	while (av[i])
	{
		ft_lstadd_back(&list_a, ft_lstnew(calculate_place(list_a,
					ft_atoi(av[i])), ft_atoi(av[i])));
		i++;
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

char	*calculate_place(t_list *list_a, int new_nbr)
{
	int	place;

	place = 0;
	t_list *tmp = list_a;
	while (tmp)
	{
	    if (tmp->number < new_nbr)
            place++;
		tmp = tmp->next;
	}
	return (ft_itoa_base(place, "0123456789"));
}


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