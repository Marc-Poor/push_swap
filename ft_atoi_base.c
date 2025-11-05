/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:19:38 by mfaure            #+#    #+#             */
/*   Updated: 2025/03/10 17:40:44 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	error_output(char *base, int disaine)
{
	int	nb;
	int	compar;

	if (disaine < 2)
		return (0);
	nb = 1;
	compar = 0;
	while (compar < disaine)
	{
		if (base[compar] == base[nb] || base[compar] == '+'
			|| base[compar] == '-' || base[compar] == ' ')
			return (0);
		nb++;
		if (nb >= disaine)
		{
			compar++;
			nb = compar + 1;
		}
	}
	return (1);
}

int	base_nbr(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	disaine;
	int	nbr;

	sign = 1;
	nbr = 0;
	i = 0;
	disaine = ft_strlen(base);
	if (!error_output(base, disaine))
		return (-1);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while ((str[i] == '+' || str[i] == '-') && str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (base_nbr(str[i], base) != -1 && str[i] != '\0')
	{
		nbr = (nbr * disaine) + (base_nbr(str[i], base));
		i++;
	}
	return (nbr * sign);
}
