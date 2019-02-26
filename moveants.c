#include "lemin.h"

void ft_move_ants(t_routearray *arraylist, t_room *exit)
{
	t_link *tmp;
	int i;
	int ant;

	ant = 0;
	i = 0;
	arraylist->way->way->room->ant = g_ants;
	while (exit->ant != g_ants)
	{
		i++;
		ft_printf("%d :", i);

		tmp = arraylist->way->way;
		while (tmp)
		{

			if (tmp->room->type == 's')
			{
				ant = tmp->room->ant;
				if (tmp->room->ant > 0)
					(tmp->room->ant)--;
			}
			else if (tmp->room->type == 'e' && ant)
			{
				ant = 0;
				(tmp->room->ant)++;
			}
			else
			{
				ft_swap(&ant, &(tmp->room->ant));
			}
			if (tmp->room->type != 's' && tmp->room->ant)
				ft_printf("L%d-%s ", tmp->room->ant, tmp->room->name);
//			if (ant == 0)
//				break;
			tmp = tmp->next;
		}
		ft_printf("\n");
	}
}