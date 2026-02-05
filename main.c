#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int			main(int ac, char **av)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(av[ac-1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
	}
	close(fd);
}
