/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:24:10 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/16 18:06:46 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int isline(char **line)
{
	size_t i;

	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}


static void	cat_buf(char *buf, char **line)
{
	char *s;

	s = ft_strjoin(*line, buf);
//	free(*line);
	*line = s;
}

static int	save(int fd, char **line, t_lst_save **lst)
{
	t_lst_save	*current;
	t_lst_save	*tmp;
	char		*rest;

	rest = ft_strchr(*line, 10);
	if (!(rest = ft_strdup(++rest)))
		return (1);
	current = *lst;
	while(current)
	{
		if (current->fd == fd)
		{
			free(current->content);
			current->content = rest;
			return (0);
		}
		current = current->next;
	}
	if (!(tmp = (t_lst_save*)malloc(sizeof(t_lst_save))))
		return (1);
	tmp->content = rest;
	tmp->fd = fd;
	current = *lst;
	tmp->next = current;
	*lst = tmp;
	printf("SAVED : %s\n", (*lst)->content);
	return (0);
}

static t_lst_save	**getback(int fd, char **line)
{
	static t_lst_save	**lst;

	if (!(lst))
	{
		if (!(lst = (t_lst_save**)malloc(sizeof(t_lst_save*))))
			return (NULL);
		*lst = NULL;
	}
	while (*lst)
	{
		if ((*lst)->fd == (size_t)fd)
		{
			*line = (*lst)->content;
			printf("FOUND\n");
			return (lst);
		}
		(*lst) = (*lst)->next;
	}
	return (lst);
}

static int set_line(int fd, t_lst_save **lst, char **line)
{
	size_t i;

	if (save(fd, line, lst))
		return (1);
	i = -1;
	while((*line)[++i])
	{
		if ((*line)[i] == '\n')
			(*line)[i + 1] = 0;
	}
	return (0);
}

int get_next_line(const int fd, char **line)
{
	int		ret;
	t_lst_save	**lst;
	char 	buf[BUF_SIZE + 1];

	if (!line)
		return (0);
	if (!(*line = (char*)malloc(1)))
		return (0);
	lst = getback(fd, line);
	//printf("line get backed : %s\n", *line);
	if (!(lst))
		return (1);
	if (isline(line))
		return (set_line(fd, lst, line));
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (ret == -1)
			return (1);
		buf[ret] = 0;
		cat_buf(buf, line);
		if (isline(line))
		{
			return (set_line(fd, lst, line));
		}
	}
	return (0);
}
