/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:31:58 by npiatiko          #+#    #+#             */
/*   Updated: 2018/11/06 13:33:32 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **lst, t_list *new)
{
	t_list *tmp;

	tmp = (*lst);
	if ((*lst) == NULL)
	{
		(*lst) = new;
		(*lst)->next = NULL;
		return ;
	}
	else
		while (tmp->next)
			tmp = tmp->next;
	tmp->next = new;
	tmp = tmp->next;
	tmp->next = NULL;
}
