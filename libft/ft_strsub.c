/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:48:34 by npiatiko          #+#    #+#             */
/*   Updated: 2018/10/31 16:06:04 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	lent;

	lent = len;
	if (((tmp = (char*)malloc(len + 1)) == 0) || s == NULL)
		return (NULL);
	s = s + start;
	while (lent)
	{
		*tmp = *s;
		tmp++;
		s++;
		lent--;
	}
	*tmp = '\0';
	return (tmp - len);
}
