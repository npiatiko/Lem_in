/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:52:30 by npiatiko          #+#    #+#             */
/*   Updated: 2018/12/12 14:52:32 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_ox(t_specifier *spec)
{
	char	*ox;

	ox = ft_strnew_chr(2, '0');
	ox[1] = spec->tp;
	spec->fl_sh = 0;
	return (ox);
}

static void		ft_width_x(char **str, t_specifier *spec, long long nbr)
{
	char		*tmp;
	size_t		len;

	*str = spec->fl_sh && nbr && !(spec->fl_zr) ?
			ft_joinstr(ft_ox(spec), *str) : *str;
	len = spec->fl_sh && nbr ? ft_strlen(*str) + 2 : ft_strlen(*str);
	if (spec->wd > 0)
	{
		if (spec->fl_mn == 0 && spec->prc == -1 && spec->fl_zr)
		{
			len = spec->wd - (int)len > 0 ? spec->wd - len : 0;
			tmp = ft_strnew_chr(len, '0');
			tmp = nbr && spec->fl_sh ? ft_joinstr(ft_ox(spec), tmp) : tmp;
		}
		else
		{
			len = spec->wd - (int)ft_strlen(*str) > 0 ?
					spec->wd - ft_strlen(*str) : 0;
			tmp = ft_strnew_chr(len, ' ');
		}
		*str = spec->fl_mn ? ft_joinstr(*str, tmp) : ft_joinstr(tmp, *str);
	}
}

char			*ft_print_x(t_specifier *spec, long long nbr)
{
	char		*str;

	nbr = spec->mdr == h ? (unsigned short int)nbr : nbr;
	nbr = spec->mdr == hh ? (unsigned char)nbr : nbr;
	nbr = spec->mdr == 0 ? (unsigned int)nbr : nbr;
	spec->fl_zr = spec->prc > -1 || spec->fl_mn ? 0 : spec->fl_zr;
	str = spec->prc == 0 && nbr == 0 ?
			ft_strnew(0) : ft_itoabase_u(nbr, spec->tp);
	if (spec->prc >= 0)
	{
		if (spec->prc - (int)ft_strlen(str) >= 0)
			str = ft_joinstr(ft_strnew_chr(spec->prc -
					ft_strlen(str), '0'), str);
		str = nbr && spec->fl_sh ? ft_joinstr(ft_ox(spec), str) : str;
	}
	ft_width_x(&str, spec, nbr);
	if (spec->fl_sh && nbr && spec->prc == -1 && spec->wd == 0)
		str = ft_joinstr(ft_ox(spec), str);
	return (str);
}
