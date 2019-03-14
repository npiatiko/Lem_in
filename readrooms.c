/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readrooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:12:44 by npiatiko          #+#    #+#             */
/*   Updated: 2019/03/14 13:12:49 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*ft_new_room(char **data, char typeroom)
{
	t_room	*new;

	if (!data[0] || !data[1] || !data[2])
		ft_exit("invalid room.", 2);
	if (data[3] || !ft_isnbr(data[1]) ||
		!ft_isnbr(data[2]) || data[0][0] == 'L')
		ft_exit("invalid room.", 2);
	if (!(new = (t_room *)ft_memalloc(sizeof(t_room))))
		ft_exit(strerror(errno), errno);
	new->name = data[0];
	new->x = ft_atoi(data[1]);
	new->y = ft_atoi(data[2]);
	free(data[1]);
	free(data[2]);
	new->type = typeroom;
	new->dist = INT_MAX;
	return (new);
}

void	ft_room_add(t_room **head, t_room *new)
{
	t_room	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (ft_strequ(new->name, tmp->name) ||
			(new->x == tmp->x && new->y == tmp->y))
			ft_exit("invalid room.", 2);
		tmp = tmp->next;
	}
	new->next = *head;
	*head = new;
}

void	ft_readroom(char *raw, char **line)
{
	char	**words;
	char	typeroom;

	typeroom = 'n';
	while (get_next_line(fd, line) > 0)
		if (**line == '#')
			ft_readcomments(*line, &typeroom, raw);
		else if (ft_count_char(*line, ' ') == 2)
		{
			words = ft_strsplit(*line, ' ');
			ft_room_add(&g_graph, ft_new_room(words, typeroom));
			free(words);
			if (typeroom == 's')
				g_start = g_graph;
			if (typeroom == 'e')
				g_exit = g_graph;
			typeroom = 'n';
			ft_save_input(raw, *line);
		}
		else if (ft_count_char(*line, '-') == 1)
			return ;
		else
			ft_exit("wrong format farm.", 1);
}
