#ifndef LEMIN_H
#define LEMIN_H

#include "./libft/libft.h"
#include <limits.h>
#define FILENAME "big-superposition"
//#define FILENAME "big"
//#define FILENAME "flow-one"
//#define FILENAME "flow-ten"
//#define FILENAME "flow-thousand"
//#define FILENAME "graph1"


int					g_ants;
typedef struct		s_room
{
	char			used;
	char			*name;
	char			type; /*s-start, e-end, n-normal*/
	int 			dist;
	int				x;
	int				y;
	int				ant;
	struct s_link	*links;
	struct s_link	*prev;
	struct s_room	*next;
}					t_room;

typedef	struct		s_link
{
	char 			used;
	struct s_room	*room;
	struct s_link	*next;
}					t_link;

typedef	struct		s_way
{
	char			used;
	struct s_link	*way;
	struct s_way	*next_way;
	int				lenway;
}					t_way;

typedef	struct		s_routearray
{
	struct s_way		*way;
	struct s_routearray	*next_array;
	int					lenway;
}					t_routearray;

t_room	*ft_parsing(t_room **start, t_room **exit);
void	ft_link_push_front(t_link **queue, t_link *newlink);
t_link	*ft_link_pop(t_link **queue);
t_link	*ft_linknew(t_room *room);
void	ft_link_push_back(t_link **queue, t_link *newlink);
void	ft_queue_rot(t_link **queue);
void	ft_print_graph(t_room *head);
void	ft_print_ways(t_way *listways);
int		ft_isnbr(char *str);
void	ft_print_list_links(t_link *way);
void	ft_BFS(t_room *start);
t_link	*ft_search_way1(t_room *exit);
void	ft_link_insert(t_link **queue, t_link *newlink);
int		ft_waylen(t_link *way);
void	ft_way_insert(t_way **listway, t_way *newway);
t_way	*ft_waynew(t_link *way);
t_link	*ft_search_way2(t_room *exit);
void		ft_resetgraph(t_room *graph);
void		ft_routeaaray_insert(t_routearray **head, t_routearray *newarray);
t_routearray	*ft_new_routearray(t_way *allways, t_way *currentway);
void ft_move_ants(t_routearray *arraylist, t_room *exit);
t_way	*ft_way_pop(t_way **listway);
t_link *ft_search_way3(t_room *exit, t_room *graph);
void	ft_way_push_front(t_way **listway, t_way *newway);
t_way	*ft_copyway(t_link *source, t_link *newlink);
#endif
