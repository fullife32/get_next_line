#include "get_next_line.h"
#include <stdio.h>

int main(int ac, char **av)
{
	char *line = NULL;
	int i = 0;
	int fd1 = 0;
	int fd2 = 0;
	int fd3 = 0;
	int fd4 = 0;

	if (ac == 1)
	{
		while (get_next_line(0, &line) > 0)
		{
			printf("%s\n", line);
			free(line);
		}
		printf("%s\n", line);
		free(line);
	}
	else if (ac == 2)
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
		fd4 = open(av[4], O_RDONLY);
		while (1)
		{
			if (fd1 != 0)
			{
				i = get_next_line(fd1, &line);
				printf("FD 1 : %s\n", line);
				free(line);
				if (i == 0)
				{
					close(fd1);
					fd1 = 0;
				}
			}
			if (fd2 != 0)
			{
				i = get_next_line(fd2, &line);
				printf("FD 2 : %s\n", line);
				free(line);
				if (i == 0)
				{
					close(fd2);
					fd2 = 0;
				}
			}
			if (fd3 != 0)
			{
				i = get_next_line(fd3, &line);
				printf("FD 3 : %s\n", line);
				free(line);
				if (i == 0)
				{
					close(fd3);
					fd3 = 0;
				}
			}
			if (fd4 != 0)
			{
				i = get_next_line(fd4, &line);
				printf("FD 4 : %s\n", line);
				free(line);
				if (i == 0)
				{
					close(fd4);
					fd4 = 0;
				}
			}
			if (fd1 == 0 && fd2 == 0 && fd3 == 0 && fd4 == 0)
			{
				//while (1);
				return (0);
			}
		}
	}
	return (0);
}

	/*else
	{
		while (ac-- != 1)
		{
			fd1 = open(av[i], O_RDONLY);
			while (get_next_line(fd1, &line) > 0)
			{
				printf("%s\n", line);
				free(line);
			}
			printf("%s\n", line);
			free(line);
			close(fd1);
			i++;
		}
	}*/