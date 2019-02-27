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
	return (newway);
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
