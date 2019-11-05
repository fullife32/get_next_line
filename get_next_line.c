/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:48:53 by eassouli          #+#    #+#             */
/*   Updated: 2019/11/05 17:04:20 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct	s_list
{
	int				fd;
	char			line[BUFFER_SIZE + 1];
	struct s_list	*next;
}				t_list;

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	len = s1 ? ft_strlen(s1) + ft_strlen(s2) : ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	isn(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	ssize_t			nread;
	ssize_t			i;
	char			*buffer;
	char			*tmpbuffer;
	static t_list	tmp;

	i = 0;
	nread = 1;
	buffer = NULL;
	*line = NULL;
	if (BUFFER_SIZE <= 0)
		return (0);
	if (isn(tmp.line) == 1)
	{
		tmpbuffer = ft_strjoin(buffer, tmp.line);
		if (buffer)
		free(buffer);
		if (!(buffer = ft_strdup(tmpbuffer)))
		{
			free(tmpbuffer);
			buffer = NULL;
			return (-1);
		}
		free(tmpbuffer);
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
			if (!(tmpbuffer = ft_strjoin(buffer, tmp.line)))
			{
				if (buffer)
					free(buffer);
				tmpbuffer = NULL;
				return (-1);
			}
			if (buffer)
				free(buffer);
			if (!(buffer = ft_strdup(tmpbuffer)))
			{
				free(tmpbuffer);
				buffer = NULL;
				return (-1);
			}
			free(tmpbuffer);
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