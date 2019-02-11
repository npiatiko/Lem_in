/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:35:49 by npiatiko          #+#    #+#             */
/*   Updated: 2018/10/31 10:46:11 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s1t;
	unsigned char *s2t;

	s1t = (unsigned char*)s1;
	s2t = (unsigned char*)s2;
	while (n)
	{
		if ((*s1t != *s2t))
			return ((int)(*s1t - *s2t));
		s1t++;
		s2t++;
		n--;
	}
	return (0);
}
