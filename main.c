#include "lemin.h"
t_way *ft_search_way(t_room *graph)
{
	t_way	*allways;
	t_link		*way;

	allways = NULL;
	ft_BFS(g_start);
	while ((way = ft_search_way3(g_exit, graph)))
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
		ft_resetdist(graph);
		ft_BFS2(g_start);
		while ((way = ft_search_way_BFS2(g_exit)))
		{
			ft_way_insert(&allways, ft_waynew(way));
			ft_resetdist(graph);
			ft_BFS2(g_start);
		}
	}
	return (allways);
}

int main()
{
	t_room		*graph;
	t_way		*allways;
	t_routearray	*arraylist;
	int iter;

	graph = ft_parsing();
	allways = ft_search_way(graph);
	arraylist = ft_listroutearray(allways, graph);
	iter = ft_printmoves(ft_bestroutearray(arraylist));
	ft_printf("my iter = %d   required = %d\n",iter, g_required);
	ft_printf("g_start = %s\n", g_start->name);
	ft_printf("g_exit = %s\n", g_exit->name);
	ft_printf("%d\n", g_ants);

	return 0;
}

int main3()
{
	t_room		*graph;
	t_room		*start;
	t_room	 	*exit;
	t_link		*way;
	t_way		*allways;
	t_way		*tmp;
	t_routearray	*arraylist;


	allways = NULL;
	arraylist = NULL;
	graph = ft_parsing();
	ft_BFS2(start);
	ft_print_graph(graph);
	while ((way = ft_search_way_BFS2(exit)))
	{
		ft_way_insert(&allways, ft_waynew(way));
//		ft_print_list_links(way);
//		ft_printf("\n");
		ft_resetdist(graph);
		ft_BFS2(start);
//		ft_print_graph(graph);
	}
//	ft_print_ways(allways);
	arraylist = (t_routearray *)malloc(sizeof(t_routearray));
	arraylist->way = allways;
	arraylist->next_array = 0;
	ft_print_ways(arraylist->way);
	start->ant = g_ants;
	exit->ant = 0;

	ft_printf("!!i = %d\n", ft_move_ants(arraylist, exit));


	ft_printf("required = %d\n", g_required);
	ft_printf("start = %s\n", start->name);
	ft_printf("exit = %s\n", exit->name);
	ft_printf("%d\n", g_ants);
	return 0;
}