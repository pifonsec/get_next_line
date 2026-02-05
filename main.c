#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	FILE	*file;
	char	*test;
	size_t	len;

	printf("---------------------------\n");
	printf("BUFFER_SIZE\t=\t%llu\n", (unsigned long long)BUFFER_SIZE);
	printf("---------------------------\n");

	if (argc != 2)
	{
		printf("Pas de fichier a lire.\n");
		return (1);
	}

	/* ===== TEST get_next_line ===== */
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}

	printf("===== get_next_line =====\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}