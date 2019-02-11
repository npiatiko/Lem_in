/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:11:33 by npiatiko          #+#    #+#             */
/*   Updated: 2018/10/31 10:42:45 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *stmp;

	stmp = (unsigned char*)s;
	while (n)
	{
		if ((unsigned char)*stmp == (unsigned char)c)
			return (stmp);
		else
		{
			n--;
			stmp++;
		}
	}
	return (NULL);
}
