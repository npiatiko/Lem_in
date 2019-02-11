/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:09:25 by npiatiko          #+#    #+#             */
/*   Updated: 2018/12/14 14:09:26 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_print_s(t_specifier *spec, char *ptr)
{
	char	*str;
	char	*tmp;
	char	c;
	size_t	len;

	spec->fl_zr = spec->fl_mn ? 0 : spec->fl_zr;
	c = (char)(spec->fl_zr ? '0' : ' ');
	str = ft_strnew(0);
	ptr = ptr ? ptr : "(null)";
	while (*ptr && spec->prc)
	{
		str = ft_joinchar(str, *ptr);
		spec->prc = spec->prc == -1 ? spec->prc : --spec->prc;
		ptr++;
	}
	len = spec->wd - (int)ft_strlen(str) < 0 ? 0 : spec->wd - ft_strlen(str);
	if (spec->wd > 0)
	{
		tmp = ft_strnew_chr(len, c);
		str = spec->fl_mn ? ft_joinstr(str, tmp) : ft_joinstr(tmp, str);
	}
	return (str);
}
