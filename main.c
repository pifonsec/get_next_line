#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int     fd;
    char    *line;

	(void)argc;
    fd = open(argv[1], O_RDONLY);

    line = get_next_line(fd);
    printf("1 >>> %s", line);
    free(line);

    line = get_next_line(fd);
    printf("2 >>> %s", line);
    free(line);

    line = get_next_line(fd);
    printf("3 >>> %s", line);
    free(line);

    close(fd);
}