/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:07:55 by npiatiko          #+#    #+#             */
/*   Updated: 2018/10/31 12:31:52 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *ptr;
	char *ptrtmp;

	if ((ptr = (char*)malloc(size)) == 0)
		return (NULL);
	ptrtmp = ptr;
	while (size)
	{
		*ptrtmp = 0;
		ptrtmp++;
		size--;
	}
	return ((void*)ptr);
}
