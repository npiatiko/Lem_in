#include "lemin.h"
t_way *ft_search_way(t_room *graph)
{
	t_way	*allways;
	t_link		*way;

	allways = NULL;
	ft_BFS(g_start);
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
		ft_resetdist(graph);
		ft_BFS2(g_start);

		while ((way = ft_search_way_BFS2(g_exit)))
		{
//			ft_printf("%p\n", way);
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

//	fd = open(FILENAME, O_RDONLY);
	fd = 0;
	graph = ft_parsing();
	allways = ft_search_way(graph);

	arraylist = ft_listroutearray(allways, graph);
	iter = ft_printmoves(ft_bestroutearray(arraylist));
	ft_printf("my iter = %d   required = %d\n",iter, g_required);
	ft_printf("g_start = %s\n", g_start->name);
	ft_printf("g_exit = %s\n", g_exit->name);
	ft_printf("%d\n", g_ants);
	system("leaks -q Lem_in");

	return 0;
}
