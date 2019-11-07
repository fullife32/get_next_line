/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:48:53 by eassouli          #+#    #+#             */
/*   Updated: 2019/11/07 16:40:48 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int				nread;
	int				i;
	char			*buffer;
	char			*buffertmp;
	static t_list	tmp;

	i = 0;
	nread = 1;
	buffer = NULL;
	*line = NULL;
	if (BUFFER_SIZE <= 0)
		return (0);
	if (isn(tmp.line) == 1)
	{
		buffertmp = ft_strjoin(buffer, tmp.line);
		if (buffer)
			free(buffer);
		if (!(buffer = ft_strdup(buffertmp)))
		{
			free(buffertmp);
			buffer = NULL;
			return (-1);
		}
		free(buffertmp);
	}
	if (isn(tmp.line) == 0)
	{
		while (nread != 0)
		{
			if ((nread = read(fd, tmp.line, BUFFER_SIZE)) == -1 || i == 1)
			{
				if (buffer)
					free(buffer);
				return (-1);
			}
			tmp.line[nread] = '\0';
			if (!(buffertmp = ft_strjoin(buffer, tmp.line)))
			{
				if (buffer)
					free(buffer);
				buffertmp = NULL;
				return (-1);
			}
			if (buffer)
				free(buffer);
			if (!(buffer = ft_strdup(buffertmp)))
			{
				free(buffertmp);
				buffer = NULL;
				return (-1);
			}
			free(buffertmp);
			if (isn(tmp.line) == 1)
				i = 1;
		}	
	}
	if (!(*line = ft_strdup(buffer)))
	{
		free(buffer);
		line = NULL;
		return (-1);
	}
	free(buffer);
	if (nread == 0)
		return (0);
	nread = ft_strlen(tmp.line) + 1;
	i = 0;
	while (tmp.line[nread] != '\0')
	{
		tmp.line[i] = tmp.line[nread];
		i++;
		nread++;
	}
	tmp.line[i] = '\0';
	return (1);
}

int main(int ac, char **av)
{
	int i = 0;
	if (ac > 1)
	{
		char *line = NULL;
		int fd = open(av[1], O_RDONLY);
		while (i < 10)
		{
			get_next_line(fd, &line);
			printf("%s\n", line);
			free(line);
			i++;
		}
	}
	return (0);
}