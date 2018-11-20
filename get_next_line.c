/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 11:50:03 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/20 15:22:38 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static int			save(const int fd, char *rest, t_lst_save **lst)
{
	t_lst_save	*current;
	t_lst_save	*tmp;

	if (!(tmp = (t_lst_save*)malloc(sizeof(t_lst_save))))
		return (0);
	current = *lst;
	while (current)
	{
		if (current->fd == (int)fd)
		{
			current->content = rest;
			return (1);
		}
		current = current->next;
	}
	tmp->content = rest;
	tmp->fd = (int)fd;
	current = *lst;
	tmp->next = current;
	*lst = tmp;
	return (1);
}

static int			last_line(int fd, char **line, int ret, t_lst_save **lst, char **s)
{
	if (ret == 0 && ft_strcmp(*s, "\0") != 0)
	{
		if (!(save(fd, "\0", lst)))
			return (-1);
		ft_strdel(line);
		*line = *s;
		ft_strdel(s);
		return (1);
	}
	return (0);
}

static int			set_line(const int fd, t_lst_save **lst, char **line, char **s)
{
	size_t	i;
	char	*rest;

	i = 0;
	while ((*s)[i] != 10 && (*s)[i] != 0)
		i++;
	if (!(rest = ft_strdup(&(*s)[i + 1])))
		return (-1);
	if (!(save(fd, rest, lst)))
		return (-1);
	*line = ft_strsub(*s, 0, i);
	ft_strdel(s);
	free(s);
	return (1);
}

static int			set_back(int fd, char **line, t_lst_save **lst, char **s)
{
	t_lst_save *current;

	if (!line)
		return (-1);
	current = *lst;
	while (current)
	{
		if (current->fd == (int)fd)
			*s = current->content;
		current = current->next;
	}
	if (ft_strchr(*s, 10))
		return (set_line(fd, lst, line, s));
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	int					ret;
	static t_lst_save	**lst;
	char				buf[BUFF_SIZE + 1];
	char				**s;

	if (!(lst))
	{
		if (!(lst = (t_lst_save**)malloc(sizeof(t_lst_save*))))
			return (-1);
		*lst = NULL;
	}
	if (!(s = (char**)malloc(sizeof(char*))))
		return (-1);
	*s = ft_strnew(1);
	ret = set_back(fd, line, lst, s);
	if (ret)
		return (ret);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = 0;
		*line = *s;
		*s = ft_strjoin(*s, buf);
		ft_strdel(line);
		if (ft_strchr(*s, 10))
			return (set_line(fd, lst, line, s));
	}
	return (last_line(fd, line, ret, lst, s));
}
