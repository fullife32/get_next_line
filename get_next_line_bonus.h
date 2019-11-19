/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:20:16 by eassouli          #+#    #+#             */
/*   Updated: 2019/11/19 22:13:41 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_list
{
	int				fd;
	char			buff[BUFFER_SIZE + 1];
	struct s_list	*next;
}				t_list;

int				ft_strlen(const char *s, char c);
char			*ft_strjoin(char *s1, char *s2);
void			ft_memmove(void *dst, const void *src, size_t len);
int				clean(char *line, t_list **first);
t_list			*ft_lstnewback(int fd, t_list **first);
t_list			*search_fd(int fd, t_list **first);
int				get_next_line(int fd, char **line);

#endif
