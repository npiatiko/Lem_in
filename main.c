#include "lemin.h"

t_room	*ft_new_room(char **data, char typeroom)
{
	t_room	*new;

	new = (t_room *)ft_memalloc(sizeof(t_room));
	new->name = ft_strdup(data[0]);
	new->x = ft_atoi(data[1]);
	new->y = ft_atoi(data[2]);
	new->type = typeroom;
	return (new);
}

void	ft_room_add(t_room **head, t_room *new)
{
	new->next = *head;
	*head = new;
}

void ft_link_add(t_room *graph, char **data)
{
	t_room *tmp;
	t_link *link;

	tmp = graph;
	while (graph)
	{
		if(ft_strequ(graph->name, data[0]))
		{
			while (tmp)
			{
				if (ft_strequ(tmp->name, data[1]))
				{
					link = ft_memalloc(sizeof(t_link));
					link->room = tmp;
					link->next = graph->links;
					graph->links = link;
					return;
				}
				tmp = tmp->next;
			}
		}
		graph = graph->next;
	}
}

void ft_print_graph(t_room *head)
{
	while (head)
	{
		ft_printf("%s, %d, %d, %c, %d", head->name, head->x, head->y, head->type, head->dist);
		while (head->links)
		{
			ft_printf(" -> %s", head->links->room->name);
			head->links = head->links->next;
		}
		ft_printf("\n");
		head = head->next;
	}
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

t_room	*ft_parsing(t_room **start)
{
	char	**words;
	char	*line;
	char	typeroom;
	t_room	*graph;
	int	fd;

	fd = open("graph", O_RDONLY);
	graph = NULL;
	g_ants = 0;
	typeroom = 'n';

	while (get_next_line(fd, &line) > 0)
	{
		if (ft_isnbr(line))
		{
			g_ants = ft_atoi(line);
			free(line);
			continue;
		}

		if (line[0] == '#' && line[1] != '#')
		{
			free(line);
			continue;
		}

		if (!ft_strncmp(line, "##", 2))
		{

			typeroom = (char)(ft_strequ(line, "##start") ? 's' : typeroom);
			typeroom = (char)(ft_strequ(line, "##end") ? 'e' : typeroom);
			free(line);
			continue;
		}

		if (ft_strchr(line, ' '))
		{
			words = ft_strsplit(line, ' ');
			ft_room_add(&graph, ft_new_room(words, typeroom));
			free(words);
			if (typeroom == 's')
				*start = graph;
		}
		typeroom = 'n';

		if (ft_strchr(line, '-'))
		{
			words = ft_strsplit(line, '-');
			ft_link_add(graph, words);
			free(words);
		}
//		ft_printf("%s\n", line);

	}
	close(fd);
	return (graph);
}

t_link	*ft_linknew(t_room *room)
{
	t_link *newlink;

	if ((newlink = (t_link *)ft_memalloc(sizeof(t_link))) == NULL)
		return (NULL);
	return (newlist);
}

void ft_searchway(t_room *graph, t_room *start)
{
	t_link	*queue;

	queue = ;
	while (queue)
	{
		while ()
		{
			if (((t_room *)(((t_room *)(queue->content))->links->content))->dist == 0)
			{
				ft_list_push_back(queue, ft_lstnew(((t_room *)(((t_room *)(queue->content))->links->content))->))
			}
		}
	}
}
int main()
{
//	ft_printf("%.0f", 1.5);
	t_room	*graph;
	t_room	*start;

	graph = ft_parsing(&start);
	ft_print_graph(graph);

	ft_printf("start = %s\n", start->name);
	ft_printf("%d\n", g_ants);
	return 0;
}