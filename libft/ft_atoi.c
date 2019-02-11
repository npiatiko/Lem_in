/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:51:34 by npiatiko          #+#    #+#             */
/*   Updated: 2018/10/29 18:12:25 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long	nbr;
	int					isnegative;

	isnegative = 1;
	nbr = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\f' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			isnegative = -1;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str - '0';
		if (nbr > 9223372036854775807 && isnegative == 1)
			return (-1);
		else if (nbr > 9223372036854775807 && isnegative == -1)
			return (0);
		str++;
	}
	return (nbr * isnegative);
}
