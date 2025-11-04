/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:18:49 by mfaure            #+#    #+#             */
/*   Updated: 2025/11/04 13:10:47 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> 

char	find_in_index(char *base, int indicator)
{
	int	i;

	i = 0;
	while (i < indicator)
		i++;
	return (base[i]);
}

int	find_size(int nb, char *base)
{
	int	size;
	int	dec;

	size = 0;
	if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	dec = ft_strlen(base);
	while (nb >= dec)
	{
		size ++;
		nb = nb / dec;
	}
	return (size + 1);
}

char	*ft_itoa_base(long nbr, char *base)
{
	char	*str;
	int		i;
	int		dec;

	str = malloc(sizeof(char) * (find_size(nbr, base) + 1));
	dec = ft_strlen(base);
	i = find_size(nbr, base);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	dec = ft_strlen(base);
	str[i] = '\0';
	i--;
	while (nbr >= dec)
	{
		str[i] = find_in_index(base, nbr % dec);
		nbr = nbr / dec;
		i--;
	}
	str[i] = find_in_index(base, nbr % dec);
	return (str);
}
