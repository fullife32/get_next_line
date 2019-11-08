/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:20:16 by eassouli          #+#    #+#             */
/*   Updated: 2019/11/07 18:53:38 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>

typedef struct	s_list
{
	int				fd;
	char			line[BUFFER_SIZE + 1];
	struct s_list	*next;
}				t_list;

size_t			ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char *s2);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				isn(char *str);
int				get_next_line(int fd, char **line);

#endif