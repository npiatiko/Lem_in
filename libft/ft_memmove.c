/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 12:18:33 by npiatiko          #+#    #+#             */
/*   Updated: 2018/10/25 17:10:49 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *dsttmp;
	char *srctmp;

	dsttmp = (char*)dst;
	srctmp = (char*)src;
	if (dst < src)
		while (len)
		{
			*dsttmp = *srctmp;
			dsttmp++;
			srctmp++;
			len--;
		}
	else
		while (len)
		{
			*(dsttmp + len - 1) = *(srctmp + len - 1);
			len--;
		}
	return (dst);
}
