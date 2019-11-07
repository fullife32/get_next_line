/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:48:53 by eassouli          #+#    #+#             */
/*   Updated: 2019/11/07 18:52:07 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	clean(char *buff, char *line)
{
	if (buff)
		free(buff);
	if (line)
		free(line);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	int				nread;
	char			*buff;
	static t_list	tmp;

	nread = 1;
	buff = NULL;
	*line = NULL;
	if (BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	while (nread != -1)
	{
		if ((nread = read(fd, tmp.line, BUFFER_SIZE)) == -1)
			return (clean(buff, *line));
		tmp.line[nread] = '\0';
		if (!(*line = ft_strjoin(*line, tmp.line)))
			return (clean(buff, *line));
		if (nread == 0)
			return (0);
		if (isn(tmp.line) != -1)
			nread = -1;
	}
	ft_strmove(*line, *line + isn(*line), ft_strlen(*line + isn(*line)));
	return (1);
}

int main(int ac, char **av)
{
	(void)ac;
	int i = 0;
	char *line = NULL;
	int fd = open(av[1], O_RDONLY);

	while (i < 10)
	{
		get_next_line(fd, &line);
		printf("%s\n", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}