#include "lemin.h"

void ft_BFS(t_room *start)
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

void ft_BFS2(t_room *start)
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
			if (tmp->room->dist == INT_MAX && !tmp->room->used)
			{
				tmp->room->dist = queue->room->dist + 1;
				if (tmp->room->type == 'n')
					ft_link_push_back(&queue, ft_linknew(tmp->room));
				tmp->room->prev = ft_linknew(queue->room);
			}
			else if (queue->room->dist + 1 < tmp->room->dist && !tmp->room->used)
			{
				tmp->room->dist = queue->room->dist + 1;
				tmp->room->prev->room = queue->room;
			}
			tmp = tmp->next;
		}
		ft_queue_pop(&queue);
	}
}

t_link	*ft_search_uprev(t_link *tmpprev)
{
	while (tmpprev)
	{
		if (tmpprev->room->used == 0)
			break ;
		tmpprev = tmpprev->next;
	}
	return (tmpprev);
}

t_link	*ft_add_step(t_link *curway, t_link *tmpprev, t_way **queueways)
{
	t_link *newstep;

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

t_way	*ft_kos(t_link **tmpway, t_way **curway, t_way **queueways, t_link **tmpprev)
{
	int	i;

	i = 0;
	while ((*tmpway)->room->type != 's')
	{
		(*tmpway)->room->used = 1;
		if ((*tmpway)->next)
			(*tmpway) = (*tmpway)->next;
		else
		if (!(*tmpprev = ft_search_uprev((*tmpway)->room->prev)))
			if (*queueways)
			{
				ft_del_way(*curway);
				if (i++ > 1000)
					return ((t_way *)5);
				*curway = ft_way_pop(queueways, tmpway);
				continue;
			}
			else
				return NULL;
		else
			(*tmpway)->next = ft_add_step((*curway)->way, *tmpprev, queueways);
	}
	return (*curway);
}

t_link *ft_search_way3(t_room *exit)
{
	static t_way *queueways = (t_way *) 1;
	t_link	*tmpway;
	t_way	*curway;
	t_link	*tmpprev;

	if (!queueways)
		return NULL;
	if (queueways == (t_way *) 1)
		queueways = ft_waynew(ft_linknew(exit));
	curway = ft_way_pop(&queueways, &tmpway);
	curway = ft_kos(&tmpway, &curway, &queueways, &tmpprev);
	if (curway == (t_way *)5)
		return ((t_link *)5);
	tmpway = curway ? curway->way : NULL;
	free(curway);
	return (tmpway);
}

t_link *ft_search_way_BFS2(t_room *exit)
{
	t_link *way;
	t_link *cur;

	way = ft_linknew(exit);
	cur = way;
	while (cur->room->prev)
	{
		if (cur->room->type == 'n')
			cur->room->used = 1;
		cur->next = ft_link_pop(&cur->room->prev);
		cur = cur->next;
	}
	if ((exit->type == 's' && cur->room->type == 'e') || (exit->type == 'e' && cur->room->type == 's'))
		return (way);
	ft_del_links(way);
	return NULL;
}
