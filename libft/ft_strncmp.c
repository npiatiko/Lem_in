/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:27:46 by npiatiko          #+#    #+#             */
/*   Updated: 2018/10/31 11:41:18 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *s1tmp;
	unsigned char *s2tmp;

	s1tmp = (unsigned char*)s1;
	s2tmp = (unsigned char*)s2;
	if (n == 0)
		return (0);
	n--;
	while (*s1tmp && *s2tmp && n)
	{
		if (*s1tmp != *s2tmp)
			return (*s1tmp - *s2tmp);
		s1tmp++;
		s2tmp++;
		n--;
	}
	return (*s1tmp - *s2tmp);
}
