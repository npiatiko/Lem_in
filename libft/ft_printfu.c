/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:42:47 by npiatiko          #+#    #+#             */
/*   Updated: 2018/12/17 13:42:47 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_width_u(char **str, t_specifier *spec)
{
	size_t	len;
	char	*tmp;
	char	c;

	c = (char)(spec->fl_zr ? '0' : ' ');
	if (spec->wd > 0)
	{
		len = spec->wd - (int)ft_strlen(*str) > 0 ?
				spec->wd - ft_strlen(*str) : 0;
		tmp = ft_strnew_chr(len, c);
		if (spec->fl_mn)
			*str = ft_joinstr(*str, tmp);
		else
			*str = ft_joinstr(tmp, *str);
	}
}

char		*ft_print_u(t_specifier *spec, long long nbr)
{
	char	*str;
	size_t	len;

	spec->mdr = spec->tp == 'U' ? ll : spec->mdr;
	nbr = spec->mdr == h ? (unsigned short int)nbr : nbr;
	nbr = spec->mdr == hh ? (unsigned char)nbr : nbr;
	nbr = spec->mdr == 0 ? (unsigned int)nbr : nbr;
	str = spec->prc == 0 && nbr == 0 ?
			ft_strnew(0) : ft_itoabase_u(nbr, spec->tp);
	spec->fl_zr = spec->fl_mn || spec->prc > -1 ? 0 : spec->fl_zr;
	if (spec->prc > -1)
	{
		len = spec->prc - (int)ft_strlen(str) > 0 ?
				spec->prc - ft_strlen(str) : 0;
		str = ft_joinstr(ft_strnew_chr(len, '0'), str);
	}
	ft_width_u(&str, spec);
	return (str);
}
