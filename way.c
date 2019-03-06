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

	newway = malloc(sizeof(t_way));
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
	while (source->next->next)
	{
		source = source->next;
		tmp->next = ft_linknew(source->room);
		tmp = tmp->next;
	}
	tmp->next = ft_linknew(newlink->room);
	return (newway);
}
void	ft_way_push_front(t_way **listway, t_way *newway)
{
	newway->next_way = *listway;
	*listway = newway;
}

t_way	*ft_way_pop(t_way **listway)
{
	t_way *way;

	if (*listway)
	{
		way = *listway;
		*listway = (*listway)->next_way;
		way->next_way = NULL;
	}
	else
		way = NULL;
	return way;
}

void	ft_way_insert(t_way **listway, t_way *newway)
{
	t_way *head;
	t_way *tmp;
	t_way *prev;

	head = (t_way*)malloc(sizeof(t_way));
	head->next_way = *listway;
	prev = head;
	tmp = head->next_way;
	while (prev->next_way)
	{
		if (newway->lenway <= tmp->lenway)
			break;
		prev = tmp;
		tmp = tmp->next_way;
	}
	prev->next_way = newway;
	newway->next_way = tmp;
	*listway = head->next_way;
	free(head);
}

void	ft_del_links(t_link *list)
{
	t_link *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void	ft_del_way(t_way *way)
{
	t_way *tmp;

	while (way)
	{
		tmp = way;
		way = way->next_way;
		ft_del_links(tmp->way);
		free(tmp);
	}
}
