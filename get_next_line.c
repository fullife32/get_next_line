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

int	clean(char *line)
{
	if (line)
		free(line);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	int				nread;
	static t_list	tmp;

	nread = ft_strlen(tmp.line + isn(tmp.line)) + 1;
	*line = NULL;
	if (line == NULL || fd < 0)
		return (-1);
	ft_memmove(tmp.line, tmp.line + isn(tmp.line) + 1, nread);
	if (!(*line = ft_strjoin(*line, tmp.line)) && tmp.line[0] != '\0')
		return (clean(*line));
	while (isn(tmp.line) == -1)
	{
		if ((nread = read(fd, tmp.line, BUFFER_SIZE)) == -1)
			return (clean(*line));
		if (nread == 0)
			return (0);
		tmp.line[nread] = '\0';
		if (!(*line = ft_strjoin(*line, tmp.line)))
			return (clean(*line));
	}
	return (1);
}
