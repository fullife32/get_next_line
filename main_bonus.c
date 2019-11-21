#include "get_next_line.h"

int main(int ac, char **av)
{
	char *line = NULL;
	int fd1 = 0;
	int fd2 = 0;
	int fd3 = 0;
	//int fd4 = 0;

	if (ac == 1)
		while (get_next_line(1, &line) > 0)
		{
			printf("%s\n", line);
			free(line);
		}
		printf("%s\n", line);
		free(line);
	if (ac == 2)
	{
		fd1 = open(av[1], O_RDONLY);
		while (get_next_line(fd1, &line) > 0)
		{
			printf("%s\n", line);
			free(line);
		}
		printf("%s\n", line);
		free(line);
		close(fd1);
	}
	else
	{
		fd1 = open(av[1], O_RDONLY);
		fd2 = open(av[2], O_RDONLY);
		fd3 = open(av[3], O_RDONLY);
		// fd1
		get_next_line(fd1, &line);
		printf("FD 1 : %s\n", line);
		free(line);
		// fd 2
		get_next_line(fd2, &line);
		printf("FD 2 : %s\n", line);
		free(line);
		// fd3
		get_next_line(fd3, &line);
		printf("FD 3 : %s\n", line);
		free(line);
		// fd1
		get_next_line(fd1, &line);
		printf("FD 1 : %s\n", line);
		free(line);
		// fd 2
		get_next_line(fd2, &line);
		printf("FD 2 : %s\n", line);
		free(line);
		// fd3
		get_next_line(fd3, &line);
		printf("FD 3 : %s\n", line);
		free(line);
		// fd1
		get_next_line(fd1, &line);
		printf("FD 1 : %s\n", line);
		free(line);
		// fd 2
		get_next_line(fd2, &line);
		printf("FD 2 : %s\n", line);
		free(line);
		// fd3
		get_next_line(fd3, &line);
		printf("FD 3 : %s\n", line);
		free(line);
		// fd1
		get_next_line(fd1, &line);
		printf("FD 1 : %s\n", line);
		free(line);
		// fd 2
		get_next_line(fd2, &line);
		printf("FD 2 : %s\n", line);
		free(line);
		// fd3
		get_next_line(fd3, &line);
		printf("FD 3 : %s\n", line);
		free(line);
		// fd1
		get_next_line(fd1, &line);
		printf("FD 1 : %s\n", line);
		free(line);
		// fd 2
		get_next_line(fd2, &line);
		printf("FD 2 : %s\n", line);
		free(line);
		// fd3
		get_next_line(fd3, &line);
		printf("FD 3 : %s\n", line);
		free(line);

		close(fd1);
		close(fd2);
		close(fd3);
	}
	// while (1);
	return (0);
}
