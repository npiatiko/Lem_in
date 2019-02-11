/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:34:49 by npiatiko          #+#    #+#             */
/*   Updated: 2018/10/26 12:07:54 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *tmp;

	tmp = dst;
	while (*src)
	{
		*tmp = *src;
		tmp++;
		src++;
	}
	*tmp = *src;
	return (dst);
}
