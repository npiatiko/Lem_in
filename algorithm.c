#include "lemin.h"


void ft_BFS(t_room *start)
{
	t_link	*queue;
	t_link	*tmp;

	start->prev = NULL;
	queue = ft_linknew(start);
	while (queue)
	{
		tmp = queue->room->links;
		while (tmp)
		{
			if (tmp->room->type != 's')
				ft_link_insert(&(tmp->room->prev), ft_linknew(queue->room));
			if (tmp->room->dist == INT_MAX)
			{
				tmp->room->dist = queue->room->dist + 1;
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

t_link *ft_search_way(t_room *exit)
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
			cur = ft_link_pop(&(cur->prev))->room;
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
			ft_printf("!!\n");
			ft_print_list_links(way);
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
