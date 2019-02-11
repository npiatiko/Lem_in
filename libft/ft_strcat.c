/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:57:01 by npiatiko          #+#    #+#             */
/*   Updated: 2018/10/26 13:24:06 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *tmp;

	tmp = s1;
	while (*tmp)
		tmp++;
	while (*s2)
	{
		*tmp = *s2;
		tmp++;
		s2++;
	}
	*(tmp) = *s2;
	return (s1);
}
