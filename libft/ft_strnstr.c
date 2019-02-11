/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:49:09 by npiatiko          #+#    #+#             */
/*   Updated: 2018/11/05 16:51:59 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*tmph;
	char	*tmpn;
	size_t	lent;

	if (*needle == 0)
		return ((char*)haystack);
	while (len && *haystack)
	{
		tmph = (char*)haystack;
		tmpn = (char*)needle;
		lent = len;
		while (*tmpn == *tmph && lent)
		{
			tmpn++;
			tmph++;
			lent--;
			if (*tmpn == 0)
				return ((char*)haystack);
		}
		len--;
		if (*haystack == 0 || len == 0)
			return (NULL);
		haystack++;
	}
	return (NULL);
}
