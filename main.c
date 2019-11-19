#include "get_next_line.h"

int main(int ac, char **av)
{
	char *line = NULL;
	int fd = 0;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line) > 0)
		{
			printf("%s\n", line);
			free(line);
		}
		printf("%s\n", line);
		free(line);
		close(fd);
	}
	return (0);
}
