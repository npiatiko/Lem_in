/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:45:40 by npiatiko          #+#    #+#             */
/*   Updated: 2018/12/14 15:45:41 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_p(t_specifier *spec)
{
	char	*ox;

	if (spec->fl_sh)
	{
		ox = ft_strdup("0x");
		spec->fl_sh = 0;
	}
	else
		ox = ft_strnew(0);
	return (ox);
}

static void	ft_width_p(char **str, t_specifier *spec)
{
	size_t	len;
	char	*tmp;
	char	c;

	c = (char)(spec->fl_zr ? '0' : ' ');
	if (spec->wd > 0)
	{
		len = spec->fl_sh ? ft_strlen(*str) + 2 : ft_strlen(*str);
		len = spec->wd - (int)len > 0 ? spec->wd - len : 0;
		tmp = ft_strnew_chr(len, c);
		if (spec->fl_mn)
			*str = ft_joinstr(ft_joinstr(ft_p(spec), *str), tmp);
		else if (spec->fl_zr)
			*str = ft_joinstr(ft_joinstr(ft_p(spec), tmp), *str);
		else
			*str = ft_joinstr(tmp, ft_joinstr(ft_p(spec), *str));
	}
}

char		*ft_print_p(t_specifier *spec, long long nbr)
{
	char	*str;
	size_t	len;

	spec->fl_sh = 1;
	spec->fl_zr = spec->fl_mn || spec->prc > -1 ? 0 : spec->fl_zr;
	str = spec->prc == 0 && nbr == 0 ?
			ft_strnew(0) : ft_itoabase_u(nbr, 'x');
	if (spec->prc > -1)
	{
		len = spec->prc - (int)ft_strlen(str) > 0 ?
				spec->prc - ft_strlen(str) : 0;
		str = ft_joinstr(ft_joinstr(ft_p(spec), ft_strnew_chr(len, '0')), str);
	}
	ft_width_p(&str, spec);
	str = spec->fl_sh ? ft_joinstr(ft_p(spec), str) : str;
	return (str);
}
