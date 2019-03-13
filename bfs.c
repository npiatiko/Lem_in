/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 12:19:21 by npiatiko          #+#    #+#             */
/*   Updated: 2019/03/13 12:19:21 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_bfs(t_room *start)
{
	t_link	*queue;
	t_link	*tmp;

	start->dist = 0;
	queue = ft_linknew(start);
	while (queue)
	{
		tmp = queue->room->links;
		while (tmp)
		{
			if (tmp->room->type != start->type)
				ft_link_insert(&(tmp->room->prev), ft_linknew(queue->room));
			if (tmp->room->dist == INT_MAX)
			{
				tmp->room->dist = queue->room->dist + 1;
				if (tmp->room->type == 'n')
					ft_link_push_back(&queue, ft_linknew(tmp->room));
			}
			else if (queue->room->dist + 1 < tmp->room->dist)
				tmp->room->dist = queue->room->dist + 1;
			tmp = tmp->next;
		}
		ft_queue_pop(&queue);
	}
}

void	ft_bfs2(t_room *start)
{
	t_link	*qu;
	t_link	*tmp;

	qu = ft_resetdist(g_graph, start);
	while (qu)
	{
		tmp = qu->room->links;
		while (tmp)
		{
			if (tmp->room->dist == INT_MAX && !tmp->room->used)
			{
				tmp->room->dist = qu->room->dist + 1;
				if (tmp->room->type == 'n')
					ft_link_push_back(&qu, ft_linknew(tmp->room));
				tmp->room->prev = ft_linknew(qu->room);
			}
			else if (qu->room->dist + 1 < tmp->room->dist && !tmp->room->used)
			{
				tmp->room->dist = qu->room->dist + 1;
				tmp->room->prev->room = qu->room;
			}
			tmp = tmp->next;
		}
		ft_queue_pop(&qu);
	}
}
