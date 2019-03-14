/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_fns1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:06:10 by npiatiko          #+#    #+#             */
/*   Updated: 2019/03/14 13:06:11 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_exit(char *errormsg, int errn)
{
	ft_printf("\033[31mError: %s\033[38m\n", errormsg);
	exit(errn);
}

void	ft_print_list_links(t_link *way)
{
	while (way)
	{
		ft_printf("%s", way->room->name);
		way = way->next;
		if (way)
			ft_printf(" -> ");
	}
}

void	ft_print_graph(t_room *head)
{
	while (head)
	{
		ft_printf("room name :%s, %c, dist = %d, used = %d",
				head->name, head->type, head->dist, head->used);
		if (head->links)
			ft_printf(" links to: ");
		ft_print_list_links(head->links);
		if (head->prev)
			ft_printf(" prev: ");
		ft_print_list_links(head->prev);
		ft_printf("\n");
		head = head->next;
	}
}

void	ft_print_ways(t_way *listways)
{
	ft_printf("\n");
	while (listways)
	{
		ft_printf("way len = %d : ", listways->lenway);
		ft_print_list_links(listways->way);
		ft_printf("\n");
		listways = listways->next_way;
	}
	ft_printf("\n");
}

int		ft_count_char(char *line, char c)
{
	int i;

	i = 0;
	while (*line)
	{
		if (*line == c)
			i++;
		line++;
	}
	return (i);
}
