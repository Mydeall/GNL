/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:30:11 by ccepre            #+#    #+#             */
/*   Updated: 2018/11/20 14:23:04 by ccepre           ###   ########.fr       */
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
	int fd1;
	int fd2;
	char **line;
	int i;
	int ret;

	if (argc != 3)
		return (0);
	if (!(line = (char**)malloc(8)))
		return (0);
	
	fd1 = open(argv[1], O_RDONLY);
	get_next_line(fd1, line);
	printf("OUTPUT : |%s|\n", *line);

	fd2 = open(argv[2], O_RDONLY);
	get_next_line(fd2, line);
	printf("OUTPUT : |%s|\n", *line);
	get_next_line(fd2, line);
	printf("OUTPUT : |%s|\n", *line);
	close(fd2);
	
	get_next_line(fd1, line);
	printf("OUTPUT : |%s|\n", *line);
	close(fd1);
	return (0);
}
