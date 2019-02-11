/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:12:16 by npiatiko          #+#    #+#             */
/*   Updated: 2018/10/31 10:35:37 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *srctmp;
	unsigned char *dsttmp;

	srctmp = (unsigned char*)src;
	dsttmp = (unsigned char*)dst;
	while (n)
	{
		if ((*dsttmp = *srctmp) == (unsigned char)c)
			return (++dsttmp);
		n--;
		dsttmp++;
		srctmp++;
	}
	return (NULL);
}
