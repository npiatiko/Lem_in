/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:17:50 by npiatiko          #+#    #+#             */
/*   Updated: 2018/10/31 11:47:24 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *tmph;
	char *tmpn;

	if (*needle == 0)
		return ((char*)haystack);
	while (*haystack)
	{
		tmph = (char*)haystack;
		tmpn = (char*)needle;
		while (*tmpn == *tmph)
		{
			tmpn++;
			tmph++;
			if (*tmpn == 0)
				return ((char*)haystack);
		}
		if (*haystack == 0)
			return (NULL);
		haystack++;
	}
	return (NULL);
}
