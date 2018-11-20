/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:30:11 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/19 10:49:52 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void    ft_putstr(char const *s);
void	ft_putchar(char c);
void    ft_putnbr(int n);

static void	display(char **line, int i)
{
	ft_putnbr(i);
	ft_putstr(" : |");
	ft_putstr(*line);
	ft_putchar('|');
	ft_putchar('\n');
}

int main(int argc, char *argv[])
{
	int fd;
	char **line;
	int i;
	int ret;

	if (argc != 2)
		return (0);
	if (!(line = (char**)malloc(8)))
		return (0);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, line);
		i++;
		printf("%s", *line);
	}
	close(fd);
	return (0);
}
