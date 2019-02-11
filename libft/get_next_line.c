/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:22:50 by npiatiko          #+#    #+#             */
/*   Updated: 2018/11/27 16:14:04 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_search_endline(char **saves, char **line)
{
	char *tofree;
	char *tmp;

	*saves = *saves == NULL ? ft_strnew(0) : *saves;
	if (!(tmp = ft_strchr(*saves, '\n')))
		return (0);
	*tmp = '\0';
	*line = ft_strdup(*saves);
	tofree = *saves;
	*saves = ft_strdup(tmp + 1);
	free(tofree);
	return (1);
}

static int		ft_read(const int fd, char **saves, char **line)
{
	char	*buf;
	char	*tmp;
	int		ret;

	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		tmp = *saves;
		buf[ret] = '\0';
		*saves = ft_strjoin(*saves, buf);
		free(tmp);
		if (ft_search_endline(saves, line))
		{
			free(buf);
			return (1);
		}
	}
	free(buf);
	return (ret == -1 ? -1 : 0);
}

static t_list	*ft_search_fd(t_list **list, const int fd)
{
	t_list *tmp;

	tmp = *list;
	while (tmp)
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		else
			tmp = tmp->next;
	tmp = (t_list*)malloc(sizeof(t_list));
	tmp->content = NULL;
	tmp->content_size = fd;
	ft_lstadd(list, tmp);
	return (*list);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	int				ret;
	t_list			*tmplist;

	if (fd < 0)
		return (-1);
	tmplist = ft_search_fd(&list, fd);
	if (ft_search_endline(((char **)(&(tmplist->content))), line))
		return (1);
	else if ((ret = ft_read(fd, ((char **)(&(tmplist->content))), line)) > 0)
		return (1);
	if (ret == 0 && *((char *)(tmplist->content)))
	{
		*line = ft_strdup(((char *)(tmplist->content)));
		free(((char *)(tmplist->content)));
		(tmplist->content) = ft_strnew(0);
		return (2);
	}
	return (ret < 0 ? -1 : 0);
}
