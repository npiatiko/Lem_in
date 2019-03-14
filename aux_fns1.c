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
	if (ft_strchr(g_params, 'c') && ft_strchr(g_params, 'e'))
		ft_printf("\033[38;05;196mError: %s\033[38m\n", errormsg);
	else if (ft_strchr(g_params, 'c'))
		ft_printf("\033[38;05;196mError.\033[38m\n", errormsg);
	else if (ft_strchr(g_params, 'e'))
		ft_printf("Error: %s\n", errormsg);
	else
		ft_printf("Error.\n");

	exit(errn);
}

void	ft_print_list_links(t_link *way)
{
	while (way)
	{
		if (ft_strchr(g_params, 'c'))
		{
			if (way->room->type == 's')
				ft_printf("\033[38;05;46m%s", way->room->name);
			else if (way->room->type == 'e')
				ft_printf("\033[38;05;21m%s", way->room->name);
			else
				ft_printf("\033[38;05;226m%s", way->room->name);
		}
		else
			ft_printf("%s", way->room->name);
		way = way->next;
		if (way)
		{
			if (ft_strchr(g_params, 'c'))
				ft_printf("\033[38;05;226m <- ");
			else
				ft_printf("\033[m <- ");
		}
	}
}

void	ft_print_ways(t_way *listways)
{
	ft_printf("\n");
	while (listways)
	{
		if (ft_strchr(g_params, 'c'))
			ft_printf("\033[38;05;15mway len = %d : ", listways->lenway);
		else
			ft_printf("way len = %d : ", listways->lenway);
		ft_print_list_links(listways->way);
		ft_printf("\n");
		listways = listways->next_way;
	}
	ft_printf("\033[m\n");
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
