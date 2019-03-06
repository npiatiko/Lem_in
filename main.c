#include "lemin.h"

int main()
{
	t_room		*graph;
	t_room		*start;
	t_room	 	*exit;
	t_link		*way;
	t_way		*allways;
	t_way		*tmp;
	t_routearray	*arraylist;
	int iter;

	allways = NULL;
	arraylist = NULL;
	graph = ft_parsing(&start, &exit);
	ft_BFS(start);
//	ft_print_graph(graph);
	while ((way = ft_search_way3(exit, graph)))
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
		ft_BFS2(start);
//		ft_print_graph(graph);
		while ((way = ft_search_way_BFS2(exit)))
		{
			ft_way_insert(&allways, ft_waynew(way));
			ft_print_list_links(way);
			ft_printf("\n");
			ft_resetdist(graph);
			ft_BFS2(start);
//			ft_print_graph(graph);

		}
	}
	tmp = allways;
	while (tmp)
	{
		ft_resetgraph(graph);
		ft_routeaaray_insert(&arraylist, ft_new_routearray(allways, tmp));
		tmp = tmp->next_way;
	}
	while (arraylist)
	{
		start->ant = g_ants;
		exit->ant = 0;
		if ((iter = ft_move_ants(arraylist, exit)) <= g_required + 2)
		{
//			ft_printf("array:\n");
//			ft_print_ways(arraylist->way);
			ft_printf("!!i = %d\n", iter);
		}
		arraylist = arraylist->next_array;
	}
	ft_printf("required = %d\n", g_required);
	ft_printf("start = %s\n", start->name);
	ft_printf("exit = %s\n", exit->name);
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
	graph = ft_parsing(&start, &exit);
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