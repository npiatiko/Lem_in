/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:13:36 by npiatiko          #+#    #+#             */
/*   Updated: 2018/10/31 15:28:13 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*tmp;

	if (s == NULL)
		return (NULL);
	len = 0;
	tmp = (char*)s;
	while (*tmp)
	{
		len++;
		tmp++;
	}
	i = 0;
	if ((tmp = (char*)malloc(len + 1)) == 0)
		return (NULL);
	while (*s)
	{
		*tmp = f(i, *s);
		tmp++;
		i++;
		s++;
	}
	*tmp = *s;
	return (tmp - len);
}
