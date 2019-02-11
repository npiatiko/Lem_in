/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:58:52 by npiatiko          #+#    #+#             */
/*   Updated: 2018/10/31 15:12:49 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	size_t	len;

	len = 0;
	if (s == NULL)
		return (NULL);
	tmp = (char*)s;
	while (*tmp)
	{
		len++;
		tmp++;
	}
	if ((tmp = (char*)malloc(len + 1)) != 0)
		while (*s)
		{
			*tmp = f(*s);
			tmp++;
			s++;
		}
	else
		return (NULL);
	*tmp = *s;
	return (tmp - len);
}
