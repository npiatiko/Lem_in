#include "lemin.h"

void ft_exit(void)
{
	ft_printf("Error:wrong format farm.\n");
	exit(3);
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

int	ft_count_char(char *line, char c)
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