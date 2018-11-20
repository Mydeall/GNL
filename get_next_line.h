/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 11:57:22 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/20 14:08:31 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 200

int						get_next_line(const int fd, char **line);

typedef struct			s_lst_save
{
	char				*content;
	int					fd;
	struct s_lst_save	*next;
}						t_lst_save;

#endif
