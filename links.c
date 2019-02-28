#include "lemin.h"

void	ft_link_insert(t_link **queue, t_link *newlink)
{
	t_link *tmp;
	t_link *prev;

	tmp = *queue;
	if (!tmp)
	{
		*queue = newlink;
		return ;
	}
	prev = NULL;
	while (tmp)
	{
		if (newlink->room->dist <= tmp->room->dist)
			break;
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}
	if (prev == NULL)
	{
		newlink->next = *queue;
		*queue = newlink;
	}
	else
	{
		newlink->next = tmp;
		prev->next = newlink;
	}
}

void	ft_link_push_front(t_link **queue, t_link *newlink)
{
	newlink->next = *queue;
	*queue = newlink;
}

t_link	*ft_link_pop(t_link **queue)
{
	t_link *link;

	if (*queue)
	{
		link = *queue;
		*queue = (*queue)->next;
		link->next = NULL;
	}
	else
		link = NULL;
	return link;
}

t_link	*ft_linknew(t_room *room)
{
	t_link *newlink;

	if ((newlink = (t_link *)malloc(sizeof(t_link))) == NULL)
		return (NULL);
	newlink->room = room;
	newlink->next = NULL;
	newlink->used = 0;
	return (newlink);
}

void	ft_link_push_back(t_link **queue, t_link *newlink)
{
	t_link *tmp;

	tmp = *queue;
	if (!tmp)
	{
		*queue = newlink;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newlink;
}

void	ft_queue_rot(t_link **queue)
{
	t_link *tmp;

	tmp = ft_link_pop(queue);
	ft_link_push_back(queue, tmp);
}
