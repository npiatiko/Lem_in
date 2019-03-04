#include "lemin.h"

void	ft_print_list_links(t_link *way)
{
	while (way)
	{
		ft_printf("%s", way->room->name, way->room->dist);
		way = way->next;
		if (way)
			ft_printf(" -> ");
	}
}

void ft_print_graph(t_room *head)
{
	while (head)
	{
		t_link *tmp;

		ft_printf("room name :%s, %c, dist = %d, used = %d", head->name, head->type, head->dist, head->used);
//		tmp = head->links;
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

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}