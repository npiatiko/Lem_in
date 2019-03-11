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
	new = (t_room *)ft_memalloc(sizeof(t_room));
	new->name = ft_strdup(data[0]);
	new->x = ft_atoi(data[1]);
	new->y = ft_atoi(data[2]);
	new->type = typeroom;
	new->dist = INT_MAX;
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

void 	ft_readcomments(char *line, char *typeroom, char *raw)
{
	static int counts = 0;
	static int counte = 0;

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
		ft_printf("Error:wrong number of start/end rooms.\n");
		exit(4);
	}
	ft_save_input(raw, line);
}

void	ft_init_ant(char *raw)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_isnbr(line) && (g_ants = ft_atoi(line)) > 0)
		{
			ft_save_input(raw, line);
			return;
		}
		else if (line[0] == '#' && line[1] != '#')
		{
			ft_save_input(raw, line);
		}
		else
		{
			ft_printf("Error:wrong number of ants.\n");
			free(line);
			exit(6);
		}
	}
}
void ft_readroom(char *raw, char **line)
{
	char	**words;
	char	typeroom;

	typeroom = 'n';
	while (get_next_line(0, line) > 0)
		if ((*line)[0] == '#')
			ft_readcomments(*line, &typeroom, raw);
		else if (ft_count_char(*line, ' ') == 2)
		{
			words = ft_strsplit(*line, ' ');
			ft_room_add(&g_graph, ft_new_room(words, typeroom));
			free(words);
			if (typeroom == 's')
				g_start = g_graph;
			if (typeroom == 'e')
				g_exit = g_graph;
			typeroom = 'n';
			ft_save_input(raw, *line);
		}
		else if (ft_count_char(*line, '-') == 1)
			return;
		else
			ft_exit();
}

void	ft_readlink(char *raw, char **line)
{
	char	**words;

	while (1)
	{
		if ((*line)[0] == '#' && (*line)[1] != '#')
		{
			ft_save_input(raw, *line);
		}
		else if (ft_count_char(*line, '-') == 1)
		{
			words = ft_strsplit(*line, '-');
			if (!words[0] || !words[1])
				ft_exit();
			ft_neighbour_add(g_graph, words);
			free(words);
			ft_save_input(raw, *line);
		}
		else
			ft_exit();
		if (get_next_line(0, line) <= 0)
			break;
	}
}

t_room *ft_parsing(void)
{
	char	*raw;
	char	*line;

	g_start = NULL;
	g_exit = NULL;
	g_graph = NULL;
	g_ants = 0;
	g_len = 0;
	raw = (char*) malloc(204800);
	*raw = 0;
	ft_init_ant(raw);
	ft_readroom(raw, &line);
	if (!g_start || !g_exit || !g_graph || !g_ants)
		ft_exit();
	ft_readlink(raw, &line);
	write(1, raw, (size_t)g_len);
	return (g_graph);
}
