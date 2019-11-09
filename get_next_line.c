/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:48:53 by eassouli          #+#    #+#             */
/*   Updated: 2019/11/09 09:39:17 by eassouli         ###   ########.fr       */
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

	nread = -1;
	buff = NULL;
	*line = NULL;
	if (line == NULL || fd < 0)
		return (-1);
	ft_memmove(tmp.line, tmp.line + isn(tmp.line) + 1, ft_strlen(tmp.line + isn(tmp.line)) + 1);
	if (!(*line = ft_strjoin(*line, tmp.line)))
		return (clean(buff, *line));
	while (isn(tmp.line) == -1)
	{
		if ((nread = read(fd, tmp.line, BUFFER_SIZE)) == -1)
			return (clean(buff, *line));
		tmp.line[nread] = '\0';
		if (!(*line = ft_strjoin(*line, tmp.line)))
			return (clean(buff, *line));
		if (nread == 0)
			return (0);
	}
	return (1);
}

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
	printf("%d\n", i);
	close(fd);
	return (0);
}