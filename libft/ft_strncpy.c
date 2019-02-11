/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:10:00 by npiatiko          #+#    #+#             */
/*   Updated: 2018/10/26 12:50:56 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *tmp;

	tmp = dst;
	while (len)
	{
		if (len && *src == 0)
		{
			*tmp = 0;
			tmp++;
			len--;
		}
		else
		{
			*tmp = *src;
			tmp++;
			src++;
			len--;
		}
	}
	return (dst);
}
