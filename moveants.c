#include "lemin.h"

int ft_calc_expr(t_way *pWay, t_link *pLink)
{
	int exp;
	int len = ft_waylen(pLink) - 1;

	exp = 0;
	while (pWay->way != pLink)
	{
		exp += len - pWay->lenway;
		pWay = pWay->next_way;
	}
	return (exp);
}

void ft_move_ants(t_routearray *arraylist, t_room *exit)
{
	t_link	*curway;
	t_way	*curlistway;
	int i;
	int ant;
	int expression;

	ant = 0;
	expression = 0;
	i = 0;
	arraylist->way->way->room->ant = g_ants;
	exit->ant = 0;
	while (exit->ant != g_ants)
	{
		i++;
//		ft_printf("%d end :%d  :", i, exit->ant);
		curlistway = arraylist->way;
		expression = 0;
		while (curlistway)
		{
			curway = curlistway->way;
			expression = ft_calc_expr(arraylist->way, curway);
//			ft_printf("exp = %d ", expression);
			while (curway)
			{

				if (curway->room->type == 'e')
				{
					if (curway->room->ant > expression)
					{
						ant = curway->room->ant;
						if (curway->room->ant > 0)
							(curway->room->ant)--;
					}
				}
				else
				{
//					if (ant)
//						ft_printf("L%d-%s ", ant, curway->room->name);
					if (curway->room->type == 'n')
						ft_swap(&ant, &(curway->room->ant));
					else if (ant)
					{
						ant = 0;
						(curway->room->ant)++;
					}
				}
				curway = curway->next;
			}
			curlistway = curlistway->next_way;
		}
//		ft_printf("\n");
	}
	ft_printf("i = %d\n", i);

}
