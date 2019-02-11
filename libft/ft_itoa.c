/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 11:54:24 by npiatiko          #+#    #+#             */
/*   Updated: 2018/11/02 15:36:33 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	long long		nbr;
	unsigned char	i;

	i = n < 0 ? 2 : 1;
	nbr = n < 0 ? -(long long)n : n;
	while ((n = n / 10) != 0)
		i++;
	if ((str = ft_strnew(i)) == NULL)
		return (NULL);
	if (nbr == 0 && i--)
		*str = '0';
	while (nbr)
	{
		i--;
		*(str + i) = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (i)
		*str = '-';
	return (str);
}
