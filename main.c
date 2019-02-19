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

void	ft_link_push_front(t_link **queue, t_link *newlink)
{
	newlink->next = *queue;
	*queue = newlink;
}

t_link	*ft_link_pop(t_link **queue)
{
	t_link *link;

	if (*queue)
	{
		link = *queue;
		*queue = (*queue)->next;
		link->next = NULL;
	}
	else
		link = NULL;
	return link;
}

t_link	*ft_linknew(t_room *room)
{
	t_link *newlink;

	if ((newlink = (t_link *)malloc(sizeof(t_link))) == NULL)
		return (NULL);
	newlink->room = room;
	newlink->next = 0;
	return (newlink);
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
					ft_link_push_front(&(graph->links), ft_linknew(tmp));
//					link = ft_memalloc(sizeof(t_link));
//					link->room = tmp;
//					link->next = graph->links;
//					graph->links = link;
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
		ft_printf("room name :%s, %c, %d", head->name, head->type, head->dist);
		if (head->links)
			ft_printf(" links to: ");
		while (head->links)
		{
			ft_printf(", %s", head->links->room->name);
			head->links = head->links->next;
		}
		if (head->prev)
			ft_printf("   prev: ");
		while (head->prev)
		{
			ft_printf(", %s", head->prev->room->name);
			head->prev = head->prev->next;
		}
		ft_printf("\n");
		head = head->next;
	}
}

void	ft_print_way(t_link *way)
{
	ft_printf("way : ");
	while (way)
	{
		ft_printf("%s -> ", way->room->name);
		way = way->next;
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

t_room *ft_parsing(t_room **start, t_room **exit)
{
	char	**words;
	char	*line;
	char	typeroom;
	t_room	*graph;
	int	fd;

	fd = open("graphbig", O_RDONLY);
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
			if (typeroom == 'e')
				*exit = graph;
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

void	ft_link_push_back(t_link **queue, t_link *newlink)
{
	t_link *tmp;

	tmp = *queue;
	if (!tmp)
	{
		*queue = newlink;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newlink;
}

void ft_BFS(t_room *start)
{
	t_link	*queue;
	t_link	*tmp;

	start->prev = NULL;
	queue = ft_linknew(start);
	while (queue)
	{
		tmp = queue->room->links;
		while (tmp)
		{
			ft_link_push_front(&(tmp->room->prev), ft_linknew(queue->room));
			if (tmp->room->dist == 0)
			{
				tmp->room->dist = queue->room->dist + 1;
				ft_link_push_back(&queue, ft_linknew(tmp->room));
			}
			tmp = tmp->next;
		}
		tmp = queue;
		queue = queue->next;
		free(tmp);
	}
}

t_link *ft_search_way(t_room *exit)
{
	t_link *way;
	t_room *cur;

//	cur = exit;
	way = ft_linknew(exit);
	if (exit->prev)
		cur = ft_link_pop(&(exit->prev))->room;
	else
		return NULL;
	while (cur)
	{
		ft_link_push_front(&way, ft_linknew(cur));
		if (cur->prev)
			cur = ft_link_pop(&(cur->prev))->room;
		else if (cur->type == 's')
			break;
		else
			return NULL;
	}
	return (way);
}

int main()
{
//	ft_printf("%.0f", 1.5);
	t_room	*graph;
	t_room	*start;
	t_room 	*exit;
	t_link	*way;

	graph = ft_parsing(&start, &exit);
	ft_BFS(start);

//	ft_print_graph(graph);
	while ((way = ft_search_way(exit)))
		ft_print_way(way);
	ft_printf("start = %s\n", start->name);
	ft_printf("exit = %s\n", exit->name);
	ft_printf("%d\n", g_ants);

	return 0;
}