/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:20:16 by eassouli          #+#    #+#             */
/*   Updated: 2019/11/21 11:05:58 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_list
{
	char	buff[BUFFER_SIZE + 1];
}				t_list;

int				clean(char **line);
int				get_next_line(int fd, char **line);
int				ft_strlen(const char *s, char c);
char			*ft_strjoin(char *s1, char *s2);
void			ft_memmove(void *dst, const void *src, size_t len);

#endif
