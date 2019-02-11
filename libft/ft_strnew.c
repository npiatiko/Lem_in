/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:07:11 by npiatiko          #+#    #+#             */
/*   Updated: 2018/11/14 19:51:15 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if ((str = (char*)malloc(size + 1)) == 0)
		return (NULL);
	while (size)
	{
		*(str + size) = '\0';
		size--;
	}
	*str = '\0';
	return (str);
}
