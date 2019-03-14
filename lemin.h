#ifndef LEMIN_H
#define LEMIN_H

#include "./libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

//#define FILENAME "big-superposition"
//#define FILENAME "big_s.txt"
//#define FILENAME "big"
//#define FILENAME "flow-one"
//#define FILENAME "flow-ten"
//#define FILENAME "flow-thousand"
#define FILENAME "graph1"

int 				g_len;
int					g_ants;
int 				g_required;
struct s_room		*g_graph;
struct s_room		*g_start;
struct s_room		*g_exit;
int fd;//

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
}					t_routearray;

char * ft_parsing();
void	ft_link_push_front(t_link **queue, t_link *newlink);
t_link	*ft_link_pop(t_link **queue);
t_link	*ft_linknew(t_room *room);
void	ft_link_push_back(t_link **queue, t_link *newlink);
void	ft_print_graph(t_room *head);
void	ft_print_ways(t_way *listways);
int		ft_isnbr(char *str);
void	ft_print_list_links(t_link *way);
void	ft_bfs(t_room *start);
void	ft_link_insert(t_link **queue, t_link *newlink);
int		ft_waylen(t_link *way);
void	ft_way_insert(t_way **listway, t_way *newway);
t_way	*ft_waynew(t_link *way);
void		ft_resetgraph(t_room *graph);
void		ft_routeaaray_insert(t_routearray **head, t_routearray *newarray);
t_routearray	*ft_new_routearray(t_way *allways, t_way *currentway);
int ft_move_ants(t_routearray *arraylist, t_room *exit);
t_way *ft_way_pop(t_way **listway, t_link **tmpway);
t_link *ft_search_way3(t_room *exit);
void	ft_way_push_front(t_way **listway, t_way *newway);
t_way	*ft_copyway(t_link *source, t_link *newlink);
void ft_bfs2(t_room *start);
t_link *ft_search_way_bfs2(t_room *exit);
t_link	*ft_resetdist(t_room *graph, t_room *start);
void	ft_del_way(t_way *way);
void	ft_del_links(t_link *list);
t_routearray	*ft_listroutearray(t_way *allways, t_room *graph);
t_routearray	*ft_bestroutearray(t_routearray	*arraylist);
int ft_printmoves(t_routearray *bestarray);
void ft_exit(char *errormsg, int errn);
int	ft_count_char(char *line, char c);
void	ft_save_input(char *raw, char *line);
void	ft_queue_pop(t_link **queue);
void			ft_visitroom(t_way *way);
int				ft_routecheck(t_way *way);
int		ft_itercounter(t_routearray *arraylist);
void	ft_readroom(char *raw, char **line);
void	ft_readcomments(char *line, char *typeroom, char *raw);
#endif
