/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 12:19:07 by npiatiko          #+#    #+#             */
/*   Updated: 2019/03/13 12:19:07 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_link	*ft_search_uprev(t_link *tmpprev, t_way *curway)
{
	while (tmpprev)
	{
		if (tmpprev->room->used == 0)
			break ;
		tmpprev = tmpprev->next;
	}
	if (!tmpprev)
		ft_del_way(curway);
	return (tmpprev);
}

t_link	*ft_add_step(t_link *curway, t_link *tmpprev, t_way **queueways)
{
	t_link	*newstep;

	newstep = ft_linknew(tmpprev->room);
	tmpprev = tmpprev->next;
	while (tmpprev)
	{
		if (tmpprev->room->used == 0)
			ft_way_push_front(queueways, ft_copyway(curway, tmpprev));
		tmpprev = tmpprev->next;
	}
	return (newstep);
}

t_way	*ft_kos(t_link **tmpway, t_way **curway,
		t_way **queueways, t_link **tmpprev)
{
	int	i;

	i = 0;
	while ((*tmpway)->room->type != 's')
	{
		(*tmpway)->room->used = 1;
		if ((*tmpway)->next)
			(*tmpway) = (*tmpway)->next;
		else if (!(*tmpprev = ft_search_uprev((*tmpway)->room->prev, *curway)))
			if (*queueways)
			{
				if (i++ > 1000)
					return ((t_way *)5);
				*curway = ft_way_pop(queueways, tmpway);
				continue;
			}
			else
				return (NULL);
		else
			(*tmpway)->next = ft_add_step((*curway)->way, *tmpprev, queueways);
	}
	return (*curway);
}

t_link	*ft_search_way3(t_room *exit)
{
	static t_way	*queueways = (t_way *)1;
	t_link			*tmpway;
	t_way			*curway;
	t_link			*tmpprev;

	if (!queueways)
		return (NULL);
	if (queueways == (t_way *)1)
		queueways = ft_waynew(ft_linknew(exit));
	curway = ft_way_pop(&queueways, &tmpway);
	curway = ft_kos(&tmpway, &curway, &queueways, &tmpprev);
	if (curway == (t_way *)5)
		return ((t_link *)5);
	tmpway = curway ? curway->way : NULL;
	free(curway);
	return (tmpway);
}

t_link	*ft_search_way_bfs2(t_room *exit)
{
	t_link	*way;
	t_link	*cur;

	way = ft_linknew(exit);
	cur = way;
	while (cur->room->prev)
	{
		if (cur->room->type == 'n')
			cur->room->used = 1;
		cur->next = ft_link_pop(&cur->room->prev);
		cur = cur->next;
	}
	if (cur->room->type == 's')
		return (way);
	ft_del_links(way);
	return (NULL);
}
