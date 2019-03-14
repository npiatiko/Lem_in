/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:16:49 by npiatiko          #+#    #+#             */
/*   Updated: 2019/03/14 13:16:50 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_link_insert(t_link **queue, t_link *newlink)
{
	t_link head;
	t_link *tmp;
	t_link *prev;

	head.next = *queue;
	prev = &head;
	tmp = head.next;
	while (prev->next)
	{
		if (newlink->room->dist <= tmp->room->dist)
			break ;
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = newlink;
	newlink->next = tmp;
	*queue = head.next;
}

void	ft_link_push_front(t_link **queue, t_link *newlink)
{
	newlink->next = *queue;
	*queue = newlink;
}

t_link	*ft_link_pop(t_link **queue)
{
	t_link *link;

	if (*queue)
	{
		link = *queue;
		*queue = (*queue)->next;
		link->next = NULL;
	}
	else
		link = NULL;
	return (link);
}

t_link	*ft_linknew(t_room *room)
{
	t_link *newlink;

	if (!(newlink = (t_link *)malloc(sizeof(t_link))))
		ft_exit(strerror(errno), errno);
	newlink->room = room;
	newlink->next = NULL;
	return (newlink);
}

void	ft_link_push_back(t_link **queue, t_link *newlink)
{
	t_link *tmp;

	tmp = *queue;
	if (!tmp)
	{
		*queue = newlink;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newlink;
}
