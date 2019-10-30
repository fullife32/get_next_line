/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:48:53 by eassouli          #+#    #+#             */
/*   Updated: 2019/10/29 23:44:27 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	get_next_line(int fd, char **line)
{
	ssize_t	i;
	ssize_t	nread;
	ssize_t	allread;
	int		findn;
	char	next_line[BUFFER_SIZE + 1];

	i = 0;
	nread = 0;
	allread = 0;
	findn = 0;
	if (BUFFER_SIZE == 0)
	while ((nread = read(fd, next_line, BUFFER_SIZE)) != 0)
	{
		if (nread == -1)
			return (-1);
		nread += allread;
		next_line[nread] = '\0';
	}
	if (!(*line = malloc(sizeof(char) * (allread + 1))))
		return (0);
	while (next_line[i] != '\0')
	{
		*line[i] = next_line[i];
		i++;
	}
	*line[i] = '\0';
	return (0);
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		char *line = NULL;
		int fd = open(av[1], O_RDONLY);
		get_next_line(fd, &line);
		printf("%s", line);
	}
	return (0);
}