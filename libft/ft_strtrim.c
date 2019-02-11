/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:42:28 by npiatiko          #+#    #+#             */
/*   Updated: 2018/11/01 12:13:57 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			len;
	char			*tmp;
	unsigned int	start;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	tmp = (char*)(s);
	start = 0;
	while ((*tmp == ' ' || *tmp == '\n' || *tmp == '\t'))
	{
		start++;
		tmp++;
		len--;
	}
	if (len == 0)
		return ((char*)(ft_strsub(s, start, len)));
	tmp = (char*)(tmp + len - 1);
	while ((*tmp == ' ' || *tmp == '\n' || *tmp == '\t'))
	{
		len--;
		tmp--;
	}
	return ((char*)(ft_strsub(s, start, len)));
}
