/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:07:50 by npiatiko          #+#    #+#             */
/*   Updated: 2018/12/17 16:07:51 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_sign(t_specifier *spec, long long nbr)
{
	char *sign;

	if (spec->fl_sh)
	{
		sign = nbr < 0 ? ft_strnew_chr(1, '-') : 0;
		sign = spec->fl_sp && nbr >= 0 ? ft_strnew_chr(1, ' ') : sign;
		sign = spec->fl_pl && nbr >= 0 ? ft_strnew_chr(1, '+') : sign;
		sign = sign == 0 ? ft_strnew(0) : sign;
		spec->fl_sh = 0;
	}
	else
		sign = ft_strnew(0);
	return (sign);
}

static void	ft_width_di(char **str, t_specifier *spec, long long nbr)
{
	size_t	len;
	char	*tmp;
	char	c;

	c = (char)(spec->fl_zr ? '0' : ' ');
	if (spec->wd > 0)
	{
		len = (nbr < 0 || (spec->fl_sp && nbr >= 0) ||
				(spec->fl_pl && nbr >= 0)) && spec->fl_sh ?
						ft_strlen(*str) + 1 : ft_strlen(*str);
		len = spec->wd - (int)len > 0 ? spec->wd - len : 0;
		tmp = ft_strnew_chr(len, c);
		if (spec->fl_mn)
			*str = ft_joinstr(ft_joinstr(ft_sign(spec, nbr), *str), tmp);
		else if (spec->fl_zr)
			*str = ft_joinstr(ft_joinstr(ft_sign(spec, nbr), tmp), *str);
		else
			*str = ft_joinstr(tmp, ft_joinstr(ft_sign(spec, nbr), *str));
	}
}

char		*ft_print_di(t_specifier *spec, long long nbr)
{
	char	*str;
	size_t	len;

	spec->fl_sh = 1;
	spec->mdr = spec->tp == 'D' ? ll : spec->mdr;
	nbr = spec->mdr == h ? (short int)nbr : nbr;
	nbr = spec->mdr == hh ? (char)nbr : nbr;
	nbr = spec->mdr == 0 ? (int)nbr : nbr;
	spec->fl_zr = spec->prc > -1 || spec->fl_mn ? 0 : spec->fl_zr;
	spec->fl_sp = spec->fl_pl ? 0 : spec->fl_sp;
	str = spec->prc == 0 && nbr == 0 ? ft_strnew(0) : ft_lltoa(nbr);
	if (spec->prc > -1)
	{
		len = spec->prc - (int)ft_strlen(str) > 0 ?
				spec->prc - ft_strlen(str) : 0;
		str = ft_joinstr(ft_joinstr(ft_sign(spec, nbr),
				ft_strnew_chr(len, '0')), str);
	}
	ft_width_di(&str, spec, nbr);
	str = ft_joinstr(ft_sign(spec, nbr), str);
	return (str);
}
