/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:12:07 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/01 21:09:59 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_listt	*ft_lstneww(t_listt *list, int fd)
{
	t_listt	*lstnew;

	if (list == NULL)
	{
		lstnew = (t_listt*)malloc(sizeof(t_listt) * 1);
		lstnew->str = NULL;
		lstnew->i = 0;
		lstnew->fd = fd;
		lstnew->next = lstnew;
	}
	else
	{
		lstnew = (t_listt*)malloc(sizeof(t_listt) * 1);
		lstnew->str = NULL;
		lstnew->fd = fd;
		lstnew->i = 1;
		lstnew->next = list->next;
	}
	return (lstnew);
}

static int		fill_line(char **str, char **line)
{
	char	*tmp;
	char	*n;

	if ((n = ft_strchr((const char*)*str, '\n')))
		*n = '\0';
	tmp = *str;
	if (!(*line = ft_strdup((const char*)*str)))
		return (0);
	if (n)
	{
		if (!(*str = ft_strdup((const char*)(n + 1))))
		{
			ft_strdel(&tmp);
			return (0);
		}
	}
	else
	{
		if (!(*str = ft_strnew(0)))
			return (0);
	}
	ft_strdel(&tmp);
	return (1);
}

static int		ft_read_line(char **str, const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	*line = NULL;
	if (*str == NULL)
	{
		if (!(*str = ft_strnew(0)))
			return (0);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = *str;
		if (!(*str = ft_strjoin(*str, buf)))
			return (0);
		ft_strdel(&tmp);
		if ((ft_strchr(*str, '\n')) != NULL)
			return (1);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_listt	*list = NULL;
	char			buftest[1];

	if (list == NULL)
		list = ft_lstneww(list, fd);
	while (list->fd != fd)
	{
		list = list->next;
		if (list->i == 0 && fd != list->fd)
		{
			while (list->next->i != 0)
				list = list->next;
			list->next = ft_lstneww(list, fd);
			list = list->next;
		}
	}
	if (fd < 0 || BUFF_SIZE <= 0 || !line || (read(fd, buftest, 0) < 0))
		return (-1);
	if (!(ft_read_line(&(list->str), fd, line)))
		return (-1);
	if (list->str[0] == '\0')
		return (0);
	if (!(fill_line(&(list->str), line)))
		return (-1);
	return (1);
}
