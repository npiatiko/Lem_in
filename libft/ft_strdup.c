/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:46:32 by npiatiko          #+#    #+#             */
/*   Updated: 2018/10/26 11:33:18 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;
	char	*tmp;

	len = 0;
	tmp = (char*)s1;
	while (*(tmp++))
		len++;
	if ((str = (char*)malloc(len + 1)) == 0)
		return (NULL);
	tmp = str;
	while ((*(tmp++) = *(s1++)))
		;
	*(str + len) = 0;
	return (str);
}
