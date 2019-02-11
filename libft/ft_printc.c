/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:43:03 by npiatiko          #+#    #+#             */
/*   Updated: 2018/12/14 12:43:04 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_c(t_specifier *spec, long long nbr)
{
	char	*tmp;
	char	c;
	size_t	len;

	spec->fl_zr = spec->fl_mn ? 0 : spec->fl_zr;
	c = (char)(spec->fl_zr ? '0' : ' ');
	if ((len = 1) && spec->wd > 0)
	{
		tmp = ft_strnew_chr(spec->wd - len, c);
		len += ft_strlen(tmp);
		if (spec->fl_mn)
		{
			ft_putchar((unsigned char)nbr);
			ft_putstr(tmp);
		}
		else
		{
			ft_putstr(tmp);
			ft_putchar((unsigned char)nbr);
		}
		free(tmp);
	}
	else
		ft_putchar((unsigned char)nbr);
	return ((int)len);
}
