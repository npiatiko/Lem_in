#include "lemin.h"

void ft_BFS(t_room *start)
{
	t_link	*queue;
	t_link	*tmp;

	start->prev = NULL;
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
		tmp = queue;
		queue = queue->next;
		free(tmp);
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
				if (tmp->room->prev)
				{
					free(tmp->room->prev);
					tmp->room->prev = ft_linknew(queue->room);
				}
			}
//			if (tmp->room->type != 'e' && !tmp->room->used && !tmp->room->prev)
//				tmp->room->prev = ft_linknew(queue->room);
			tmp = tmp->next;
		}
		tmp = queue;
		queue = queue->next;
		free(tmp);
	}
}

t_link *ft_search_way1(t_room *exit)
{
	t_link *way;
	t_room *cur;

//	cur = exit;
	way = ft_linknew(exit);
	if (exit->prev)
		cur = ft_link_pop(&(exit->prev))->room;
	else
		return NULL;
	while (cur)
	{
		ft_link_push_front(&way, ft_linknew(cur));
		if (cur->prev && !(cur->used))
		{
//			cur->used = 1;//(char) (cur->type == 's' ? 0 : 1);
//			cur = ft_link_pop(&(cur->prev))->room;
			cur = cur->prev->room;
//			ft_queue_rot(&(cur->prev));
		}
		else if (cur->type == 's')
		{
			cur->used = 0;
			break;
		}

		else if (exit->prev)
		{
			cur = ft_link_pop(&(exit->prev))->room;
			way = ft_linknew(exit);
		}
		else
		{
//			ft_printf("!!\n");
//			ft_print_list_links(way);
			return NULL;
		}
	}
	return (way);
}

t_link *ft_search_way2(t_room *exit)
{
	t_link	*way;
	t_room	*cur;
	t_room	*tmp;
	char 	newway;

	cur = exit;
	newway = 0;
	way = NULL;
//	way = ft_linknew(exit);
//	cur = exit->prev->room;
//	newway = (char)(exit->prev->used ? 0 : 1);
//	exit->prev->used = 1;
//	ft_queue_rot(&(exit->prev));
	while (cur)
	{
		ft_link_push_front(&way, ft_linknew(cur));
		if (cur->prev)
		{
			newway = (char)(cur->prev->used ? newway : 1);
			cur->prev->used = 1;
			tmp = cur;
			cur = cur->prev->room;
//			if (!newway)
				ft_queue_rot(&(tmp->prev));
		}
		else if (cur->type == 's')
			break;
	}
	if (newway)
		return way;
	else
	{
//		ft_printf("!!!!!!!\n");
//		ft_print_list_links(way);
		return (NULL);
	}
}

t_link *ft_search_way3(t_room *exit, t_room *graph)
{
	static t_way *queueways = (t_way *) 1;
	t_link	*tmpway;
	t_way	*curway;
	t_link	*tmpprev;
	int 	i = 0;

	if (!queueways)
		return NULL;
	if (queueways == (t_way *) 1)
	{
		queueways = ft_waynew(ft_linknew(exit));
	}
	ft_resetgraph(graph);
	curway = ft_way_pop(&queueways);
	tmpway = curway->way;
	while (tmpway->room->type != 's')
	{
//		ft_printf("cyclecount %d \n", i);

		tmpway->room->used = 1;
		if (tmpway->next)
		{
			(curway->lenway)++;
			tmpway = tmpway->next;
		}
		else
		{
			tmpprev = tmpway->room->prev;
			while (tmpprev)
			{
				if (tmpprev->room->used == 0)// && tmpprev->room->dist <= tmpway->room->dist)
					break ;
				tmpprev = tmpprev->next;
			}
			if (tmpprev == NULL)// || curway->lenway > 100)// || tmpprev->room->dist > tmpway->room->dist)
			{
				if (queueways)
				{
					if (i++ > 1000)
						return ((t_link *)5);
					ft_resetgraph(graph);
					ft_del_way(curway);
					curway = ft_way_pop(&queueways);
					tmpway = curway->way;
					continue;
				}
				else
					return NULL;
			}
			tmpway->next = ft_linknew(tmpprev->room);
//			tmpprev->room->used = 1;
			tmpprev = tmpprev->next;
//			tmpprev = tmpway->room->prev;
//			ft_print_list_links(curway->way);
//			ft_printf("!!!\n");
			while (tmpprev)
			{
//				ft_printf("!!!\n");
//				ft_print_list_links(curway->way);
				if (tmpprev->room->used == 0)// && curway->lenway < 50)// && tmpprev->room->dist <= tmpway->room->dist)
					ft_way_push_front(&queueways, ft_copyway(curway->way, tmpprev));
				tmpprev = tmpprev->next;
			}
		}
	}
	tmpway = curway->way;
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
	return NULL;
}
