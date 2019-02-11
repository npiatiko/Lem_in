/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:34:33 by npiatiko          #+#    #+#             */
/*   Updated: 2018/11/06 13:34:36 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	int				i;
	unsigned char	tmp;
	int				bits[8];

	tmp = octet;
	i = -1;
	while (++i < 8)
	{
		bits[i] = tmp % 2;
		tmp = tmp / 2;
	}
	while (--i != -1)
	{
		tmp = bits[i] + '0';
		write(1, &tmp, 1);
	}
}
