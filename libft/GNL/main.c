#include "get_next_line.h"

int main (int argc, char **argv)
{
	int	i;
	int	fd;
	char *line;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
}