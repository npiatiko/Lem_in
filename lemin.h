#ifndef LEMIN_H
#define LEMIN_H

#include "./libft/libft.h"
#include <limits.h>
#define FILENAME "graphbigsuper"

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
	struct s_link	*way;
	struct s_way	*next_way;
	int				lenway;
}					t_way;

typedef	struct		s_massway
{
	struct s_way		*way;
	struct s_massway	*next_mass;
	int					lenway;
}					t_massway;

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
t_link	*ft_search_way(t_room *exit);
void	ft_link_insert(t_link **queue, t_link *newlink);
int		ft_waylen(t_link *way);
void	ft_way_insert(t_way **listway, t_way *newway);
t_way	*ft_waynew(t_link *way);
t_link *ft_search_way2(t_room *exit);
#endif
