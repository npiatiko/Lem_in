#include "lemin.h"

int main()
{
//	ft_printf("%.0f", 1.5);
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
	ft_BFS(start);

	ft_print_graph(graph);
	while ((way = ft_search_way2(exit)))
	{
		ft_way_insert(&allways, ft_waynew(way));
	}
//	ft_print_ways(allways);
	tmp = allways;
	while (tmp)
	{
		ft_resetgraph(graph);
		ft_routeaaray_insert(&arraylist, ft_new_routearray(allways, tmp));
		tmp = tmp->next_way;
	}
	while (arraylist)
	{
		ft_printf("array:\n");
		ft_print_ways(arraylist->way);
		ft_move_ants(arraylist, exit);
		arraylist = arraylist->next_array;
	}
//	ft_print_graph(graph);
	ft_printf("start = %s\n", start->name);
	ft_printf("exit = %s\n", exit->name);
	ft_printf("%d\n", g_ants);

	return 0;
}