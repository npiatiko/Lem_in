/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:30:14 by npiatiko          #+#    #+#             */
/*   Updated: 2018/12/07 13:30:14 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init_width(t_specifier *spec, char **format, va_list va)
{
	if (ft_isdigit(**format))
	{
		spec->wd = ft_atoi(*format);
		*format = *format + ft_nbrlen(spec->wd);
	}
	else
	{
		spec->wd = va_arg(va, int);
		if (spec->wd < 0)
		{
			spec->wd = -spec->wd;
			spec->fl_mn = 1;
		}
		(*format)++;
	}
}

static void	ft_init_precision(t_specifier *spec, char **format, va_list va)
{
	(*format)++;
	if (**format == '*')
	{
		spec->prc = va_arg(va, int);
		spec->prc = spec->prc < 0 ? -1 : spec->prc;
		(*format)++;
	}
	else
	{
		spec->prc = ft_atoi(*format) ? ft_atoi(*format) : 0;
		*format += ft_isdigit(**format) ? ft_nbrlen(spec->prc) : 0;
	}
}

static void	ft_init_flag(t_specifier *spec, char **format)
{
	spec->fl_pl = **format == '+' ? 1 : spec->fl_pl;
	spec->fl_mn = **format == '-' ? 1 : spec->fl_mn;
	spec->fl_sh = **format == '#' ? 1 : spec->fl_sh;
	spec->fl_sp = **format == ' ' ? 1 : spec->fl_sp;
	spec->fl_zr = **format == '0' ? 1 : spec->fl_zr;
	(*format)++;
}

static void	ft_init_modifier(t_specifier *spec, char **format)
{
	t_modifier tmp;

	tmp = 0;
	tmp = **format == 'h' ? h : tmp;
	tmp = **format == 'l' ? l : tmp;
	tmp = ft_strchr("zj", **format) ? ll : tmp;
	tmp = **format == 'L' ? L : tmp;
	(*format)++;
	tmp = **format == 'h' && tmp == h ? hh : tmp;
	tmp = **format == 'l' && tmp == l ? ll : tmp;
	if (**format == 'h' || **format == 'l')
		(*format)++;
	spec->mdr = tmp > spec->mdr ? tmp : spec->mdr;
}

void		initspecifier(t_specifier *spec, char **format, va_list va)
{
	resetspecifier(spec);
	while (**format)
		if (ft_strchr("+- #0", **format))
			ft_init_flag(spec, format);
		else if (ft_isdigit(**format) || **format == '*')
			ft_init_width(spec, format, va);
		else if (**format == '.')
			ft_init_precision(spec, format, va);
		else if (ft_strchr("hlLzj", **format))
			ft_init_modifier(spec, format);
		else
		{
			spec->tp = **format;
			break ;
		}
}
