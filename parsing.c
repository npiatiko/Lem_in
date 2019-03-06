#include "lemin.h"

t_room	*ft_new_room(char **data, char typeroom)
{
	t_room	*new;

	new = (t_room *)malloc(sizeof(t_room));
	new->name = ft_strdup(data[0]);
	new->x = ft_atoi(data[1]);
	new->y = ft_atoi(data[2]);
	new->type = typeroom;
//	new->dist = typeroom == 's' ? 0 : INT_MAX;
//	new->dist = typeroom == 'e' ? 0 : INT_MAX;
	new->dist = INT_MAX;
	new->links = NULL;
	new->prev = NULL;
	new->next = NULL;
	new->used = 0;
	new->ant = 0;
	return (new);
}

void	ft_room_add(t_room **head, t_room *new)
{
	new->next = *head;
	*head = new;
}

void ft_neighbour_add(t_room *graph, char **data)
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

//					if (graph->type != 'e' && tmp->type != 's')
//					if (graph->type != 's' && tmp->type != 'e')
						ft_link_push_front(&(graph->links), ft_linknew(tmp));
//					if (tmp->type != 'e' && graph->type != 's')
//					if (tmp->type != 's' && graph->type != 'e')
						ft_link_push_front(&(tmp->links), ft_linknew(graph));
					return;
				}
				tmp = tmp->next;
			}
		}
		graph = graph->next;
	}
}

t_room *ft_parsing(t_room **start, t_room **exit)
{
	char	**words;
	char	*line;
	char	typeroom;
	t_room	*graph;
	int	fd;

	fd = open(FILENAME, O_RDONLY);
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
			if (ft_strcmp(line, "#Here is the number of lines required: "))
				g_required = ft_atoi(line + 38);
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
			ft_neighbour_add(graph, words);
			free(words);
		}
//		ft_printf("%s\n", line);

	}
	close(fd);
	return (graph);
}
