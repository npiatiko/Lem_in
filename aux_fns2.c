/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_fns2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 12:29:33 by npiatiko          #+#    #+#             */
/*   Updated: 2019/03/13 12:29:33 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_resetgraph(t_room *graph)
{
	while (graph)
	{
		graph->used = 0;
		graph = graph->next;
	}
}

t_link	*ft_resetdist(t_room *graph, t_room *start)
{
	while (graph)
	{
		graph->dist = graph->type == 's' ? 0 : INT_MAX;
		ft_del_links(graph->prev);
		graph->prev = NULL;
		graph = graph->next;
	}
	return (ft_linknew(start));
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

int ft_isnbr(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return 1;
}
