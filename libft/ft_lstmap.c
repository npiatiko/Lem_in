/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:16:33 by npiatiko          #+#    #+#             */
/*   Updated: 2018/11/05 16:15:34 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstadd_end(t_list **lst, t_list *new)
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

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;

	tmp = NULL;
	while (lst)
	{
		ft_lstadd_end(&tmp, f(lst));
		lst = lst->next;
	}
	return (tmp);
}
