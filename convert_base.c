/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaure <mfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:00:25 by mfaure            #+#    #+#             */
/*   Updated: 2025/11/04 14:00:40 by mfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nbr_decimal;
	char	*new_nbr;

	if (!error_output(base_from, ft_strlen(base_from))
		|| !error_output(base_to, ft_strlen(base_to)))
		return (NULL);
	nbr_decimal = ft_atoi_base(nbr, base_from);
	new_nbr = ft_itoa_base(nbr_decimal, base_to);
	return (new_nbr);
}