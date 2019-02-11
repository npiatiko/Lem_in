/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprinto.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:52:46 by npiatiko          #+#    #+#             */
/*   Updated: 2018/12/12 14:52:49 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_print_o(t_specifier *spec, long long nbr)
{
	char		*str;
	char		*tmp;
	long long	n;

	n = nbr;
	spec->mdr = spec->tp == 'O' ? ll : spec->mdr;
	n = spec->mdr == h ? (unsigned short int)nbr : n;
	n = spec->mdr == hh ? (unsigned char)nbr : n;
	n = spec->mdr == 0 ? (unsigned int)nbr : n;
	str = spec->prc == 0 && nbr == 0 ?
			ft_strnew(0) : ft_itoabase_u(n, spec->tp);
	if (spec->fl_sh && (nbr || spec->prc == 0))
		str = ft_joinstr(ft_strnew_chr(1, '0'), str);
	if ((spec->prc) > (int)ft_strlen(str))
		str = ft_joinstr(ft_strnew_chr(spec->prc - ft_strlen(str), '0'), str);
	if (spec->wd > (int)ft_strlen(str))
	{
		if (spec->fl_mn == 0 && spec->prc == -1 && spec->fl_zr)
			tmp = ft_strnew_chr(spec->wd - ft_strlen(str), '0');
		else
			tmp = ft_strnew_chr(spec->wd - ft_strlen(str), ' ');
		str = spec->fl_mn ? ft_joinstr(str, tmp) : ft_joinstr(tmp, str);
	}
	return (str);
}
