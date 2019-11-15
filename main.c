#include "get_next_line.h"

int main(int ac, char **av)
{
	int i = 1;
	char *line = NULL;
	int fd = 0;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (i > 0)
		{
			i = get_next_line(fd, &line);
			printf("%s\n", line);
			free(line);
		}
		close(fd);
	}
	else
	{
		while (i > 0)
		{
			i = get_next_line(0, &line);
			printf("%s\n", line);
			free(line);
		}
		close(fd);
	}	
	// while (1);
	return (0);
}