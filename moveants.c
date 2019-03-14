/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:54:57 by npiatiko          #+#    #+#             */
/*   Updated: 2019/03/13 13:54:58 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_calc_expr(t_way *pway, t_link *plink)
{
	int exp;
	int len;

	len = ft_waylen(plink) - 1;
	exp = 0;
	while (pway->way != plink)
	{
		exp += len - pway->lenway;
		pway = pway->next_way;
	}
	return (exp);
}

void	ft_moveant(t_link *curway, int expression)
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
}
void	ft_print_moveant(t_link *curway, int expression)
{
	while (curway->next && g_exit->ant != g_ants)
	{
		if (curway->room->type == 'e' && curway->next->room->type == 's')
		{
			ft_printf("L%03d-%s ", curway->next->room->ant, curway->room->name);
			g_start->ant--;
			g_exit->ant++;
			continue;
		}
		else
			ft_moveant(curway, expression);
		curway = curway->next;
	}
}

int		ft_itercounter(t_routearray *arraylist)
{
	t_link	*curway;
	t_way	*curlistway;
	int		i;
	int		expression;
	int		ants;

	i = 0;
	ants = g_ants;
	while (ants)
	{
		curlistway = arraylist->way;
		i++;
		while (curlistway)
		{
			curway = curlistway->way;
			expression = ft_calc_expr(arraylist->way, curway);
			if (ants > expression)
				ants--;
			else
				break ;
			curlistway = curlistway->next_way;
		}
	}
	return (i + arraylist->way->lenway - 1);
}

int		ft_printmoves(t_routearray *bestarray)
{
	t_link	*curway;
	t_way	*curlistway;
	int		expression;
	int		i;

	i = 0;
	g_start->ant = g_ants;
	g_exit->ant = 0;
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
