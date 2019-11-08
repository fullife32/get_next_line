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
	if (BUFFER_SIZE <= 0 || line == NULL || fd < 0)
		return (-1);
	if (isn(tmp.line) != -1)
		nread = -1;
	ft_memmove(tmp.line, tmp.line + isn(tmp.line) + 1, ft_strlen(tmp.line + isn(tmp.line)) + 1);
	if (!(*line = ft_strjoin(*line, tmp.line)))
		return (clean(buff, *line));
	while (nread != -1)
	{
		if ((nread = read(fd, tmp.line, BUFFER_SIZE)) == -1)
			return (clean(buff, *line));
		tmp.line[nread] = '\0';
		if (nread == 0)
			return (0);
		if (!(*line = ft_strjoin(*line, tmp.line)))
			return (clean(buff, *line));
	}
	return (1);
}

int main(int ac, char **av)
{
	(void)ac;
	int i = 1;
	char *line = NULL;
	int fd = open(av[1], O_RDONLY);

	while (i != 0)
	{
		i = get_next_line(fd, &line);
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}