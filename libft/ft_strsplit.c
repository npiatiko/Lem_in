/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 12:17:20 by npiatiko          #+#    #+#             */
/*   Updated: 2018/11/05 12:15:05 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_iwords(char **arrwords, char const *s, char c)
{
	unsigned int	n;

	while (*s)
	{
		n = 0;
		while (*s != c && *s != '\0')
		{
			n++;
			s++;
			if (*s == c || *s == '\0')
				*arrwords++ = ft_strnew(n);
		}
		if (*s != '\0')
			s++;
	}
	*arrwords = NULL;
}

static char		**ft_createwords(char const *s, char c, unsigned int *n)
{
	char	**arrwords;
	char	*tmp;

	*n = 0;
	if ((tmp = (char*)s) == NULL)
		return (NULL);
	while (*tmp)
	{
		if (*tmp != c && (*(tmp + 1) == c || *(tmp + 1) == '\0'))
			*n = *n + 1;
		tmp++;
	}
	return (arrwords = (char**)malloc(sizeof(char*) * (*n + 1)));
}

char			**ft_strsplit(char const *s, char c)
{
	char			**arrwords;
	char			*tmp;
	unsigned int	n;

	if (!(arrwords = ft_createwords(s, c, &n)))
		return (NULL);
	ft_iwords(arrwords, s, c);
	while (*s)
	{
		tmp = *arrwords;
		while (*s != c && *s != '\0')
		{
			if (*arrwords == NULL)
				return (NULL);
			*tmp = *s;
			tmp++;
			s++;
			if (*s == c || *s == '\0')
				arrwords++;
		}
		if (*s != '\0')
			s++;
	}
	return (arrwords - n);
}
