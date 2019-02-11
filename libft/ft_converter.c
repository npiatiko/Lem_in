/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:03:07 by npiatiko          #+#    #+#             */
/*   Updated: 2018/12/11 15:39:22 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoabase_u(unsigned long long int nbr, int base)
{
	char				*num;
	char				*str;
	unsigned long long	unbr;
	size_t				len;

	num = base == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	base = base == 'x' || base == 'X' ? 16 : base;
	base = ft_strchr("oO", base) ? 8 : base;
	base = ft_strchr("DdiUu", base) ? 10 : base;
	unbr = nbr;
	len = nbr == 0 ? 1 : 0;
	while (nbr)
	{
		len++;
		nbr = nbr / base;
	}
	str = ft_strnew(len);
	str[0] = '0';
	while (unbr)
	{
		str[len - 1] = num[unbr % base];
		unbr = unbr / base;
		len--;
	}
	return (str);
}

char	*ft_lltoa(long long nbr)
{
	char				*num;
	char				*str;
	unsigned long long	unbr;
	size_t				len;

	num = "0123456789";
	unbr = (unsigned long long int)(nbr < 0 ? -nbr : nbr);
	len = nbr == 0 ? 1 : 0;
	while (nbr)
	{
		len++;
		nbr = nbr / 10;
	}
	str = ft_strnew(len);
	str[0] = '0';
	while (unbr)
	{
		str[len - 1] = num[unbr % 10];
		unbr = unbr / 10;
		len--;
	}
	return (str);
}
