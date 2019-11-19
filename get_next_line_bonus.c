/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:48:53 by eassouli          #+#    #+#             */
/*   Updated: 2019/11/20 00:45:23 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		clean(char *line, t_list **first)
{
	t_list			*lst;
	t_list			*nxt;
	
	if (line)
		free(line);
	line = NULL;
	if (first)
	{
		lst = *first;
		while (lst != NULL)
		{
			nxt = lst->next;
			free(lst);
			lst = nxt;
		}
	}
	first = NULL;
	return (-1);
}

t_list	*ft_lstnewback(int fd, t_list **first)
{
	t_list			*lst;
	t_list			*new;

	lst = *first;
	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	if (*first == NULL)
		*first = new;
	else
	{
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = new;
	}
	return (new);
}

t_list	*search_fd(int fd, t_list **first)
{
	t_list			*lst;

	lst = *first;
	while (lst != NULL)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (ft_lstnewback(fd, first));
}

int		get_next_line(int fd, char **line)
{
	static t_list	*first = NULL;
	t_list			*lst;
	int				nread;

	*line = NULL;
	if (line == NULL || fd < 0 || BUFFER_SIZE < 0)
		return (-1);
	if (!(lst = search_fd(fd, &first)))
		return (clean(*line, &first));
	if (ft_strlen(lst->buff, '\0') > 0)
		if (!(*line = ft_strjoin(*line, lst->buff)))
			return (clean(*line, &first));
	while (ft_strlen(lst->buff, '\n') == -1)
	{
		if ((nread = read(fd, lst->buff, BUFFER_SIZE)) < 0)
			return (clean(*line, &first));
		lst->buff[nread] = '\0';
		if (!(*line = ft_strjoin(*line, lst->buff)))
			return (clean(*line, &first));
		if (nread == 0)
			return (0);
	}
	nread = ft_strlen(lst->buff + ft_strlen(lst->buff, '\n'), '\0') + 1;
	ft_memmove(lst->buff, lst->buff + ft_strlen(lst->buff, '\n') + 1, nread);
	return (1);
}
