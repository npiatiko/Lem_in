/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:32:34 by npiatiko          #+#    #+#             */
/*   Updated: 2018/12/20 14:32:35 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_rounding(long double nbr, long long *intpart, char *fract)
{
	int		flag;
	size_t	len;

	len = ft_strlen(fract);
	flag = nbr * (long double)2 >= 1 ? 1 : 0;
	while (flag && len)
	{
		if (fract[len - 1] + 1 < 10 + '0')
		{
			fract[len - 1]++;
			flag = 0;
		}
		else
		{
			fract[len - 1] = '0';
			len--;
		}
	}
	*intpart = flag ? ++(*intpart) : *intpart;
}

static char		*ft_fract(long double nbr, int precision, char **intstr)
{
	char		*fract;
	long long	intpart;

	intpart = (long long)nbr;
	nbr = nbr - (long double)intpart;
	fract = ft_strnew(0);
	while (precision--)
	{
		nbr *= 10;
		fract = ft_joinchar(fract, (char)((long long)nbr % 10 + '0'));
		nbr = nbr - (long long)nbr;
	}
	ft_rounding(nbr, &intpart, fract);
	*intstr = ft_lltoa(intpart);
	return (fract);
}

static char		*ft_sign_db(t_specifier *spec, long double nbr)
{
	char	*sign;

	if (spec->tp)
	{
		sign = ((*(((char*)&nbr) + 9)) >> 7) ? ft_strnew_chr(1, '-') : 0;
		sign = spec->fl_sp && !((*(((char*)&nbr) + 9)) >> 7) ?
			ft_strnew_chr(1, ' ') : sign;
		sign = spec->fl_pl && !((*(((char*)&nbr) + 9)) >> 7) ?
			ft_strnew_chr(1, '+') : sign;
		sign = sign == 0 ? ft_strnew(0) : sign;
		spec->tp = 0;
	}
	else
		sign = ft_strnew(0);
	return (sign);
}

static void		ft_width_db(char **str, t_specifier *spec, long double nbr)
{
	size_t	len;
	char	*tmp;
	char	c;

	c = (char)(spec->fl_zr ? '0' : ' ');
	if (spec->wd > 0)
	{
		len = (nbr < 0 || (spec->fl_sp && nbr >= 0) ||
			(spec->fl_pl && nbr >= 0)) && spec->tp ?
				ft_strlen(*str) + 1 : ft_strlen(*str);
		len = spec->wd - (int)len > 0 ? spec->wd - len : 0;
		tmp = ft_strnew_chr(len, c);
		if (spec->fl_mn)
			*str = ft_joinstr(ft_joinstr(ft_sign_db(spec, nbr), *str), tmp);
		else if (spec->fl_zr)
			*str = ft_joinstr(ft_joinstr(ft_sign_db(spec, nbr), tmp), *str);
		else
			*str = ft_joinstr(tmp, ft_joinstr(ft_sign_db(spec, nbr), *str));
	}
}

char			*ft_print_double(t_specifier *spec, long double nbr)
{
	char	*str;
	char	*point;
	char	*mant;

	spec->tp = 1;
	spec->fl_zr = spec->fl_mn ? 0 : spec->fl_zr;
	spec->fl_sp = spec->fl_pl ? 0 : spec->fl_sp;
	spec->prc = spec->prc == -1 ? 6 : spec->prc;
	point = spec->prc || spec->fl_sh ? ft_strnew_chr(1, '.') : ft_strnew(0);
	mant = ft_fract(nbr > 0.0 ? nbr : -nbr, spec->prc, &str);
	str = ft_joinstr(ft_joinstr(str, point), mant);
	ft_width_db(&str, spec, nbr);
	str = ft_joinstr(ft_sign_db(spec, nbr), str);
	return (str);
}
