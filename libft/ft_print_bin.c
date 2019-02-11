/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:26:43 by npiatiko          #+#    #+#             */
/*   Updated: 2018/12/26 16:26:43 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*dispbit(void *d, int size)
{
	unsigned char	*data;
	char			*str;
	char			*byte;
	int				j;

	str = ft_strnew(0);
	data = (unsigned char *)d;
	while (size--)
	{
		j = 7;
		byte = ft_strnew(8);
		while (j > -1)
		{
			byte[j] = (char)(data[size] % 2 + '0');
			data[size] = (unsigned char)(data[size] / 2);
			j--;
		}
		str = *str ? ft_joinchar(str, ' ') : str;
		str = ft_joinstr(str, byte);
	}
	return (str);
}

char		*ft_print_bin(t_specifier *spec, long long int data)
{
	int		size;

	size = spec->mdr == 0 ? 4 : 0;
	size = spec->mdr == ll ? 8 : size;
	size = spec->mdr == h ? 2 : size;
	size = spec->mdr == hh ? 1 : size;
	return (dispbit(&data, size));
}
