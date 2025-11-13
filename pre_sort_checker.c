/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:58:08 by mfaure            #+#    #+#             */
/*   Updated: 2025/11/13 19:32:50 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	count;

	count = i;
	while (av[i])
	{
		if (ft_atoi(av[i]) > ft_atoi(av[i - 1]))
			count++;
		i++;
	}
	if (count == ac)
		return (0);
	return (1);
}
