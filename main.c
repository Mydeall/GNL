#include "get_next_line.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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

	if (argc != 2)
		return (0);
	if (!(line = (char**)malloc(8)))
		return (0);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, line);
	i++;
	display(line, i);
	get_next_line(fd, line);
	i++;
	display(line, i);
	get_next_line(fd, line);
	i++;
	display(line, i);
	get_next_line(fd, line);
	i++;
	display(line, i);
	get_next_line(fd, line);
	i++;
	display(line, i);
	get_next_line(fd, line);
	i++;
	display(line, i);
	get_next_line(fd, line);
	i++;
	display(line, i);
	get_next_line(fd, line);
	i++;
	display(line, i);
	get_next_line(fd, line);
	i++;
	display(line, i);
	close(fd);
	printf("DONE\n");
	return (0);
}
