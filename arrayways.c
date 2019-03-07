#include "lemin.h"

void	ft_resetgraph(t_room *graph)
{
	while (graph)
	{
		graph->used = 0;
		graph = graph->next;
	}
}

void	ft_resetdist(t_room *graph)
{
	while (graph)
	{
		graph->dist = INT_MAX;
		ft_del_links(graph->prev);
		graph->prev = NULL;
		graph = graph->next;
	}
}

void	ft_visitroom(t_way *way)
{
	t_link *tmp;

	tmp = way->way;
	while (tmp)
	{
		if (tmp->room->type == 'n')
			tmp->room->used = 1;
		tmp = tmp->next;
	}
}

int		ft_routecheck(t_way *way)
{
	t_link *tmp;

	tmp = way->way;
	while (tmp)
	{
		if (tmp->room->used)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_routearray	*ft_new_routearray(t_way *allways, t_way *currentway)
{
	t_routearray *newarray;

	newarray = NULL;
	ft_visitroom(currentway);
//	if (!(currentway->used))
	if (1)
	{
		newarray = (t_routearray *) malloc(sizeof(t_routearray));
//		currentway->used = 1;
		newarray->way = ft_waynew(currentway->way);
		newarray->next_array = 0;
	}
	while (allways)
	{
		if (!allways->used && ft_routecheck(allways))
		{
			if (!newarray)
			{
				newarray = (t_routearray *)malloc(sizeof(t_routearray));
				currentway->used = 1;
				newarray->way = ft_waynew(currentway->way);
				newarray->next_array = 0;
			}
			ft_visitroom(allways);
//			allways->used = 1;
			ft_way_insert(&(newarray->way), ft_waynew(allways->way));
		}
		allways = allways->next_way;
	}
	return (newarray);
}

void	ft_routeaaray_insert(t_routearray **head, t_routearray *newarray)
{
	if (newarray)
	{
		newarray->next_array = *head;
		*head = newarray;
	}
}

t_routearray	*ft_listroutearray(t_way *allways, t_room *graph)
{
	t_way			*tmp;
	t_routearray	*arraylist;

	arraylist = NULL;
	tmp = allways;
	while (tmp)
	{
		ft_resetgraph(graph);
		ft_routeaaray_insert(&arraylist, ft_new_routearray(allways, tmp));
		tmp = tmp->next_way;
	}
	return (arraylist);
}

t_routearray	*ft_bestroutearray(t_routearray	*arraylist)
{
	int				iter;
	int				tmp;
	t_routearray	*bestarray;

	iter = INT_MAX;
	bestarray = NULL;
	while (arraylist)
	{
		g_start->ant = g_ants;
		g_exit->ant = 0;
		if ((tmp = ft_move_ants(arraylist, g_exit)) < iter)
		{
			iter = tmp;
			bestarray = arraylist;
		}
		arraylist = arraylist->next_array;
	}
	return (bestarray);
}