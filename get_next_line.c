/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:48:53 by eassouli          #+#    #+#             */
/*   Updated: 2019/11/15 23:50:26 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	clean(char *line)
{
	if (line)
		free(line);
	line = NULL;
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	int				nread;
	static t_list	tmp;

	*line = NULL;
	nread = 1;
	if (line == NULL || fd < 0 || BUFFER_SIZE < 0)
		return (-1);
	if (ft_strlen(tmp.buff, '\0') > 0)
		if (!(*line = ft_strjoin(*line, tmp.buff)))
			return (clean(*line));
	while (ft_strlen(tmp.buff, '\n') == -1)
	{
		if ((nread = read(fd, tmp.buff, BUFFER_SIZE)) < 0)
			return (clean(*line));
		tmp.buff[nread] = '\0';
		if (!(*line = ft_strjoin(*line, tmp.buff)))
			return (clean(*line));
		if (nread == 0)
			return (0);
	}
	nread = ft_strlen(tmp.buff + ft_strlen(tmp.buff, '\n'), '\0') + 1;
	ft_memmove(tmp.buff, tmp.buff + ft_strlen(tmp.buff, '\n') + 1, nread);
	return (1);
}
