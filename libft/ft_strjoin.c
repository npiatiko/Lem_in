/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:06:24 by npiatiko          #+#    #+#             */
/*   Updated: 2018/10/31 17:38:56 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*tmp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((tmp = ft_strnew(len)) == 0)
		return (NULL);
	while (*s1 || *s2)
		if (*s1)
		{
			*tmp = *s1;
			tmp++;
			s1++;
		}
		else if (*s2)
		{
			*tmp = *s2;
			tmp++;
			s2++;
		}
	*tmp = '\0';
	return (tmp - len);
}
