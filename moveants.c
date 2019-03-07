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

void	ft_move_ant(t_link *curway, int expression)
{
	while (curway->next)
	{
		if (curway->room->type == 'e' && curway->next->room->ant)
		{
//			ft_printf("L%d-%s ", curway->next->room->ant, curway->room->name);
			curway->room->ant++;
			curway->next->room->ant = 0;
		}
		else if (curway->next->room->type == 's' && curway->next->room->ant)
		{
			if (curway->next->room->ant > expression)
			{
				curway->room->ant = curway->next->room->ant;
//				ft_printf("L%d-%s ", curway->room->ant, curway->room->name);
				curway->next->room->ant--;
			}
		}
		else if (curway->next->room->ant)
		{
			curway->room->ant = curway->next->room->ant;
//			ft_printf("L%d-%s ", curway->room->ant, curway->room->name);
			curway->next->room->ant = 0;
		}
		curway = curway->next;
	}
}

void	ft_print_moveant(t_link *curway, int expression)
{
	while (curway->next)
	{
		if (curway->room->type == 'e' && curway->next->room->ant)
		{
			ft_printf("L%03d-%s ", curway->next->room->ant, curway->room->name);
			curway->room->ant++;
			curway->next->room->ant = 0;
		}
		else if (curway->next->room->type == 's' && curway->next->room->ant)
		{
			if (curway->next->room->ant > expression)
			{
				curway->room->ant = curway->next->room->ant;
				ft_printf("L%03d-%s ", curway->room->ant, curway->room->name);
				curway->next->room->ant--;
			}
		}
		else if (curway->next->room->ant)
		{
			curway->room->ant = curway->next->room->ant;
			ft_printf("L%03d-%s ", curway->room->ant, curway->room->name);
			curway->next->room->ant = 0;
		}
		curway = curway->next;
	}
}

int ft_move_ants(t_routearray *arraylist, t_room *exit)
{
	t_link	*curway;
	t_way	*curlistway;
	int i;
	int expression;

	i = 0;
	while (exit->ant != g_ants)
	{
		i++;
		curlistway = arraylist->way;
		while (curlistway)
		{
			curway = curlistway->way;
			expression = ft_calc_expr(arraylist->way, curway);
			ft_move_ant(curway, expression);
			curlistway = curlistway->next_way;
		}
	}
	return i;
}
int ft_printmoves(t_routearray *bestarray)
{
	t_link	*curway;
	t_way	*curlistway;
	int expression;
	int i;

	i = 0;
	g_start->ant = g_ants;
	g_exit->ant = 0;
	curlistway = bestarray->way;
	while (g_exit->ant != g_ants)
	{
		i++;
		curlistway = bestarray->way;
		while (curlistway)
		{
			curway = curlistway->way;
			expression = ft_calc_expr(bestarray->way, curway);
			ft_print_moveant(curway, expression);
			curlistway = curlistway->next_way;
		}
		ft_printf("\n");
	}
	return (i);
}