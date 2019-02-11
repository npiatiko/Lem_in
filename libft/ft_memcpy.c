/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:42:41 by npiatiko          #+#    #+#             */
/*   Updated: 2018/10/25 11:14:22 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *dsttmp;
	char *srctmp;

	srctmp = (char*)src;
	dsttmp = (char*)dst;
	while (n)
	{
		*dsttmp = *srctmp;
		n--;
		dsttmp++;
		srctmp++;
	}
	return (dst);
}
