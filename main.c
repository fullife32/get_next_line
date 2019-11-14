#include "get_next_line.h"

int main(int ac, char **av)
{
	(void)ac;
	int i = 1;
	char *line = NULL;
	int fd = (ac == 1) ? 0 : open(av[1], O_RDONLY);

	while (i > 0)
	{
		i = get_next_line(fd, &line);
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	//while (1);
	return (0);
}