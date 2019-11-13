/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:15:23 by eassouli          #+#    #+#             */
/*   Updated: 2019/11/09 09:09:16 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int				i;
	int				j;
	int				len;
	char			*str;

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
	while (s2 && s2[j] != '\n' && s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	if (s1)
		free(s1);
	return (str);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*dest;
	unsigned char	*source;

	i = 0;
	dest = dst;
	source = (unsigned char *)src;
	while (len-- != 0)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

int		isn(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
