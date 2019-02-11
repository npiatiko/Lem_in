/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:39:37 by npiatiko          #+#    #+#             */
/*   Updated: 2018/10/29 10:41:27 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lend;
	size_t	lens;
	char	*tmp;

	lens = 0;
	tmp = (char*)src;
	while (*(tmp++))
		lens++;
	tmp = dst;
	lend = 0;
	while (*(tmp++))
		lend++;
	if (dstsize <= lend)
		return (dstsize + lens);
	tmp = dst + lend;
	while (dstsize - lend - 1 && *src)
	{
		*tmp = *src;
		tmp++;
		src++;
		dstsize--;
	}
	*tmp = 0;
	return (lend + lens);
}
