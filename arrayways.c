#include "lemin.h"

void	ft_resetgraph(t_room *graph)
{
	while (graph)
	{
		graph->used = 0;
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

	ft_visitroom(currentway);
	newarray = (t_routearray *)malloc(sizeof(t_routearray));
	newarray->way = ft_waynew(currentway->way);
	newarray->next_array = 0;
	while (allways)
	{
		if (ft_routecheck(allways))
		{
			ft_visitroom(allways);
			ft_way_insert(&(newarray->way), ft_waynew(allways->way));
		}
		allways = allways->next_way;
	}
	return (newarray);
}

void	ft_routeaaray_insert(t_routearray **head, t_routearray *newarray)
{
	newarray->next_array = *head;
	*head = newarray;
}