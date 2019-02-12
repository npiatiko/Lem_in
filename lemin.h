#ifndef LEMIN_H
#define LEMIN_H

#include "./libft/libft.h"

typedef struct		s_room
{
	char			*name;
	char			type; /*s-start, e-end, n-normal*/
	int				x;
	int				y;
	struct s_room	*link;
	struct s_room	*next;
}					t_room;
int					g_ants;

#endif
