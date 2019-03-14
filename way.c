/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:35:57 by npiatiko          #+#    #+#             */
/*   Updated: 2019/03/13 15:35:58 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_waylen(t_link *way)
{
	int len;

	len = 0;
	while (way)
	{
		len++;
		way = way->next;
	}
	return (len);
}

t_way	*ft_waynew(t_link *way)
{
	t_way *newway;

	if (!(newway = (t_way *)malloc(sizeof(t_way))))
		ft_exit(strerror(errno), errno);
	newway->used = 0;
	newway->way = way;
	newway->lenway = ft_waylen(way) - 1;
	newway->next_way = NULL;
	return (newway);
}

t_way	*ft_copyway(t_link *source, t_link *newlink)
{
	t_way	*newway;
	t_link	*tmp;

	newway = ft_waynew(NULL);
	newway->way = ft_linknew(source->room);
	tmp = newway->way;
	while (source->next)
	{
		source = source->next;
		tmp->next = ft_linknew(source->room);
		tmp = tmp->next;
	}
	tmp->next = ft_linknew(newlink->room);
	return (newway);
}

t_way	*ft_way_pop(t_way **listway, t_link **tmpway)
{
	t_way *way;

	if (*listway)
	{
		ft_resetgraph(g_graph);
		way = *listway;
		*listway = (*listway)->next_way;
		way->next_way = NULL;
		*tmpway = way->way;
	}
	else
		way = NULL;
	return (way);
}

void	ft_way_insert(t_way **listway, t_way *newway)
{
	t_way head;
	t_way *tmp;
	t_way *prev;

	head.next_way = *listway;
	prev = &head;
	tmp = head.next_way;
	while (prev->next_way)
	{
		if (newway->lenway <= tmp->lenway)
			break ;
		prev = tmp;
		tmp = tmp->next_way;
	}
	prev->next_way = newway;
	newway->next_way = tmp;
	*listway = head.next_way;
}
