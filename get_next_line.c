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

void	ft_bzero(void *s, size_t n)
{
	while (n-- != 0)
		((char *)s)[n] = 0;
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
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
	len = (s1 ? ft_strlen(s1) + ft_strlen(s2) : ft_strlen(s2));
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

int	get_next_line(int fd, char **line)
{
	ssize_t	nread;
	char	buffer[BUFFER_SIZE + 1];
	char	*linetmp;

	nread = 1;
	linetmp = NULL;
	*line = NULL;
	if (BUFFER_SIZE <= 0)
		return (0);
	ft_bzero(buf, BUFFER_SIZE + 1);
	nread = read(fd, buf, BUFFER_SIZE);
	while ((nread != 0 && )
	//{
		if (nread == -1)
		{
			if (*line != NULL)
				free(*line);
			return (-1);
		}
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
	//}
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