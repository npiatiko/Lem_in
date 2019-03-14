/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:28:48 by npiatiko          #+#    #+#             */
/*   Updated: 2019/03/13 15:28:48 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void ft_print_move(int ant, t_room *room)
{
	if (ft_strchr(g_params, 'c'))
	{
		if (room->type == 'n')
			ft_printf("\033[38;05;226mL%03d-%s ", ant, room->name);
		else
			ft_printf("\033[38;05;21mL%03d-%s ", ant, room->name);
	}
	else
		ft_printf("L%03d-%s ", ant, room->name);
}

void	ft_help(void)
{
	ft_printf("\033[31musage : lem-in [--aceh] < [map]\n\t--c - colour output."
		"\n\t--a - display additional information."
	"\n\t--e - display error message\n\t--h - display this message.\033[38m\n");
	exit(43);
}

void	ft_params(int ac, char **av)
{
	int		i;

	i = 0;
	g_params[i] = '\0';
	if (ac > 2)
		ft_help();
	if (ac == 2)
	{
		if (ft_strncmp(av[1], "--", 2) || ft_strchr(av[1], 'h'))
			ft_help();
		while (*(av[1] + 2))
		{
			if (ft_strchr("cahe", *(av[1] + 2)))
			{
				g_params[i] = *(av[1] + 2);
				i++;
				g_params[i] = '\0';
			}
			else
				ft_help();
			av[1]++;
		}
	}
}

t_way	*ft_search_way(t_room *graph)
{
	t_way	*allways;
	t_link	*way;

	allways = NULL;
	ft_bfs(g_start);
	while ((way = ft_search_way3(g_exit)))
	{
		if (way == (t_link *)5)
			break ;
		ft_way_insert(&allways, ft_waynew(way));
	}
	if (way == (t_link *)5)
	{
		ft_del_way(allways);
		allways = NULL;
		ft_resetgraph(graph);
		ft_bfs2(g_start);
		while ((way = ft_search_way_bfs2(g_exit)))
		{
			ft_way_insert(&allways, ft_waynew(way));
			ft_bfs2(g_start);
		}
	}
	return (allways);
}

int		main(int ac, char **av)
{
	t_way			*allways;
	t_routearray	*arraylist;
	char			*input;
	int				iter;

	ft_params(ac, av);
	input = ft_parsing();
	if (!(allways = ft_search_way(g_graph)))
		ft_exit("ways not found.", 56);
	write(1, input, (size_t)g_len);
	arraylist = ft_listroutearray(allways, g_graph);
	if (ft_strchr(g_params, 'a'))
		ft_print_ways(ft_bestroutearray(arraylist)->way);
	iter = ft_printmoves(ft_bestroutearray(arraylist));
	system("leaks -q Lem_in");
	if (ft_strchr(g_params, 'a'))
	{
		ft_printf("my iter = %d   required = %d\n", iter, g_required);
		ft_printf("start = %s\n", g_start->name);
		ft_printf("exit = %s\n", g_exit->name);
		ft_printf("ants in farm : %d\n", g_ants);
	}
	return (0);
}
