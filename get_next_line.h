/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:24:40 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/16 18:07:10 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define BUF_SIZE 2

int				get_next_line(const int fd, char **line);

typedef struct		s_lst_save
{
	char				*content;
	unsigned int		fd;
	struct s_lst_save	*next;
}					t_lst_save;

#endif
