/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrayways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 12:26:38 by npiatiko          #+#    #+#             */
/*   Updated: 2019/03/13 12:26:38 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_routearray	*ft_new_routearray(t_way *allways, t_way *currentway)
{
	t_routearray *newarray;

	ft_visitroom(currentway);
	if(!(newarray = (t_routearray *)malloc(sizeof(t_routearray))))
		ft_exit(strerror(errno), errno);
	newarray->way = ft_waynew(currentway->way);
	newarray->next_array = 0;
	while (allways)
	{
		if (!allways->used && ft_routecheck(allways))
		{
			ft_visitroom(allways);
			ft_way_insert(&(newarray->way), ft_waynew(allways->way));
		}
		allways = allways->next_way;
	}
	return (newarray);
}

void			ft_routeaaray_insert(t_routearray **head,
		t_routearray *newarray)
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

t_routearray	*ft_bestroutearray(t_routearray *arraylist)
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
		if ((tmp = ft_itercounter(arraylist)) < iter)
		{
			iter = tmp;
			bestarray = arraylist;
		}
		arraylist = arraylist->next_array;
	}
	return (bestarray);
}
