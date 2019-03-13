/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_fns3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:40:07 by npiatiko          #+#    #+#             */
/*   Updated: 2019/03/13 15:40:08 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_way_push_front(t_way **listway, t_way *newway)
{
	newway->next_way = *listway;
	*listway = newway;
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

void	ft_save_input(char *raw, char *line)
{
	ft_strcat(raw + g_len, line);
	g_len = g_len + (int)ft_strlen(line);
	free(line);
	ft_strcat(raw + g_len, "\n");
	g_len++;
}

void	ft_queue_pop(t_link **queue)
{
	t_link *tmp;

	tmp = *queue;
	*queue = (*queue)->next;
	free(tmp);
}
