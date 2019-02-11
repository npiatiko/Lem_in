/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_fns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:34:31 by npiatiko          #+#    #+#             */
/*   Updated: 2018/12/20 12:34:31 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(int num)
{
	int len;

	len = num == 0 ? 1 : 0;
	while (num)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_joinchar(char *str, char c)
{
	char *newstr;

	newstr = ft_strnew(2);
	newstr[0] = c;
	newstr = ft_joinstr(str, newstr);
	return (newstr);
}

char	*ft_strnew_chr(size_t len, char c)
{
	char *str;

	str = (char*)malloc(len + 1);
	str[len] = '\0';
	while (len)
	{
		str[len - 1] = c;
		len--;
	}
	return (str);
}

void	resetspecifier(t_specifier *spec)
{
	spec->fl_mn = 0;
	spec->fl_pl = 0;
	spec->fl_sh = 0;
	spec->fl_sp = 0;
	spec->fl_zr = 0;
	spec->mdr = 0;
	spec->prc = -1;
	spec->tp = 0;
	spec->wd = 0;
}

char	*ft_joinstr(const char *s1, const char *s2)
{
	size_t	len;
	char	*tmp;
	char	*s1tmp;
	char	*s2tmp;

	s2tmp = (char*)s2;
	if (!(s1tmp = (char*)s1) || !(s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((tmp = ft_strnew(len)) == 0)
		return (NULL);
	while (*s1 || *s2)
		if (*s1)
			*tmp++ = *s1++;
		else if (*s2)
			*tmp++ = *s2++;
	free(s1tmp);
	free(s2tmp);
	*tmp = '\0';
	return (tmp - len);
}
