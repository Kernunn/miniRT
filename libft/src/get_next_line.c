/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorros <gmorros@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 12:01:23 by gmorros           #+#    #+#             */
/*   Updated: 2020/10/14 23:50:57 by gmorros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

#	ifndef BUFFER_SIZE
#	define BUFFER_SIZE 42
#	endif

static char	*ft_strjoin_v2(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	char	*new;

	if (!s1 && !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new)
	{
		i = 0;
		k = 0;
		while (s1 && s1[i] && s1[i] != '\n')
		{
			new[i] = s1[i];
			i++;
		}
		while (s2 && *s2 != '\0' && *s2 != '\n')
			new[i + k++] = *s2++;
		new[i + k] = '\0';
		free((char *)s1);
		return (new);
	}
	return (NULL);
}

static int	ft_remainder(char **line, char **remainder, char **n_here)
{
	char	*tmp;

	*n_here = NULL;
	if (*remainder)
	{
		tmp = *remainder;
		*n_here = ft_strchr(*remainder, '\n');
		if (!(*line = ft_strjoin_v2(*line, *remainder)))
			return (1);
		if (*n_here)
		{
			if (!(*remainder = ft_strdup(*n_here + 1)))
				return (1);
			free(tmp);
		}
		else
		{
			free(*remainder);
			*remainder = NULL;
		}
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			count_read;
	static char	*remainder;
	char		*n_here;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || !(*line = ft_strdup("")))
		return (-1);
	count_read = 0;
	if (ft_remainder(line, &remainder, &n_here))
		return (-1);
	while (!n_here && (count_read = read(fd, buf, BUFFER_SIZE)))
	{
		if (count_read == -1)
			return (-1);
		buf[count_read] = '\0';
		if ((n_here = ft_strchr(buf, '\n')))
		{
			remainder = ft_strdup(n_here + 1);
			*line = ft_strjoin_v2(*line, buf);
			return ((*line && remainder) ? 1 : -1);
		}
		else if (!(*line = ft_strjoin_v2(*line, buf)))
			return (-1);
	}
	return ((n_here || count_read) ? 1 : 0);
}
