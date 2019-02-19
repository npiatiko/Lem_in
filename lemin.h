#ifndef LEMIN_H
#define LEMIN_H

#include "./libft/libft.h"

int					g_ants;
typedef struct		s_room
{
	char			*name;
	char			type; /*s-start, e-end, n-normal*/
	int 			dist;
	int				x;
	int				y;
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
	struct s_room	*room;
	struct s_way	*next;
}					t_way;

#endif
