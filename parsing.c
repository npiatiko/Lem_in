#include "lemin.h"

t_room	*ft_new_room(char **data, char typeroom)
{
	t_room	*new;

	if (!data[0] || !data[1] || !data[2])
	{
		ft_printf("Error:invalid room.\n");
		exit(2);
	}
	if (data[3] || !ft_isnbr(data[1]) || !ft_isnbr(data[2]) || data[0][0] == 'L')
	{
		ft_printf("Error:invalid room.\n");
		exit(2);
	}
	new = (t_room *)malloc(sizeof(t_room));
	new->name = ft_strdup(data[0]);
	new->x = ft_atoi(data[1]);
	new->y = ft_atoi(data[2]);
	new->type = typeroom;
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
	t_room	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (ft_strequ(new->name, tmp->name) || (new->x == tmp->x && new->y == tmp->y))
		{
			ft_printf("Error:invalid room.\n");
			exit(2);
		}
		tmp = tmp->next;
	}
	new->next = *head;
	*head = new;
}

void ft_neighbour_add(t_room *graph, char **data)
{
	t_room *tmp;

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
					ft_link_push_front(&(tmp->links), ft_linknew(graph));
					return;
				}
				tmp = tmp->next;
			}
		}
		graph = graph->next;
	}
	ft_printf("Error:wrong link.\n");
	exit(1);
}

void	ft_init_ant(int *stage, char *line)
{
	if (*stage != 0)
	{
		ft_printf("Error:wrong format file.\n");
		exit(3);
	}
	if (ft_isnbr(line))
	{
		g_ants = ft_atoi(line);
		*stage = 1;
	}
	else
	{
		ft_printf("Error:wrong number of ants.\n");
		exit(6);
	}
}

void 	ft_readcomments(char *line, char *typeroom)
{
	static int	counts = 0;
	static int	counte = 0;

	if (line[1] != '#')
	{
		if (ft_strcmp(line, "#Here is the number of lines required: "))
			g_required = ft_atoi(line + 38);
	}
	if (ft_strequ(line, "##start"))
	{
		*typeroom = 's';
		counts++;
	}
	if (ft_strequ(line, "##end"))
	{
		*typeroom = 'e';
		counte++;
	}
	if (counte > 1 || counts > 1)
	{
		ft_printf("Error:wrong number of start/end rooms");
		exit(4);
	}
}
void ft_readroom(char *line, int *stage, char *typeroom)
{
	char	**words;

	if (ft_strchr(line, ' '))
	{
		words = ft_strsplit(line, ' ');
		ft_room_add(&g_graph, ft_new_room(words, *typeroom));
		free(words);
		if (*typeroom == 's')
			g_start = g_graph;
		if (*typeroom == 'e')
			g_exit = g_graph;
		*stage = 2;
	}
	else
	{
		ft_printf("Error:wrong format farm.\n");
		exit(3);
	}
	*typeroom = 'n';
}

void	ft_readlink(char *line, int *stage)
{
	char	**words;

	if (ft_strchr(line, '-'))
	{
		words = ft_strsplit(line, '-');
		if (!words[0] || !words[1])
		{
			ft_printf("Error:wrong format farm.\n");
			exit(3);
		}
		ft_neighbour_add(g_graph, words);
		free(words);
		*stage = 3;
	}
	else
	{
		ft_printf("Error:wrong format farm.\n");
		exit(3);
	}
}

t_room *ft_parsing(void)
{
	char	*line;
	char	typeroom;
	int		stage;
	int		fd;

	fd = open(FILENAME, O_RDONLY);
	g_graph = NULL;
	g_ants = 0;
	typeroom = 'n';
	stage = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '#')
		{
			ft_readcomments(line, &typeroom);
			continue;
		}
		if (stage == 0)
			ft_init_ant(&stage, line);
		else if (stage == 1 || stage == 2)
			ft_readroom(line, &stage, &typeroom);
		else if (stage == 2 || stage == 3)
			ft_readlink(line, &stage);
		free(line);
	}
	close(fd);
	return (g_graph);
}
