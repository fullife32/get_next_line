/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:48:53 by eassouli          #+#    #+#             */
/*   Updated: 2019/11/15 14:51:56 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	clean(char *line)
{
	if (line)
		free(line);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	int			nread;
	static char	buff[BUFFER_SIZE + 1];

	nread = 0;
	*line = NULL;
	if (line == NULL || fd < 0)
		return (-1);
	if (ft_strlen(buff, '\0') > 0)
	{
		if (!(*line = ft_strjoin(*line, buff)))
			return (clean(*line));
	}
	while (ft_strlen(buff, '\n') == -1)
	{
		if ((nread = read(fd, buff, BUFFER_SIZE)) == -1)
			return (clean(*line));
		buff[nread] = '\0';
		if (!(*line = ft_strjoin(*line, buff)))
			return (clean(*line));
		if (nread == 0)
			return (0);
	}
	nread = ft_strlen(buff + ft_strlen(buff, '\n'), '\0') + 1;
	ft_memmove(buff, buff + ft_strlen(buff, '\n') + 1, nread);
	return (1);
}
