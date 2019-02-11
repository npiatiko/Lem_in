/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <exam@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:58:45 by exam              #+#    #+#             */
/*   Updated: 2018/11/30 17:52:01 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_list_size(t_list *begin_list)
{
	size_t	size;

	size = 0;
	if (begin_list == 0)
		return (0);
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}
