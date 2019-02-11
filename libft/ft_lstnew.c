/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 12:43:34 by npiatiko          #+#    #+#             */
/*   Updated: 2018/11/05 18:49:40 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlist;

	if ((newlist = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
		newlist->next = NULL;
		return (newlist);
	}
	if ((newlist->content = (void *)malloc(content_size)) == NULL)
	{
		free(newlist);
		return (NULL);
	}
	ft_memcpy(newlist->content, content, content_size);
	newlist->content_size = content_size;
	newlist->next = NULL;
	return (newlist);
}
