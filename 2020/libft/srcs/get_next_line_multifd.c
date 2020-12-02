/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_multifd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:01:33 by mdesfont          #+#    #+#             */
/*   Updated: 2020/02/24 12:48:05 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <limits.h>

char		*gnl_strjoin(char *s1, char const *s2)
{
	size_t	len_s1;
	char	*tmp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	tmp = ft_strdup(s1);
	if (!(s1 = malloc(sizeof(char) * (len_s1 + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(s1, tmp);
	free(tmp);
	ft_strcpy(s1 + len_s1, s2);
	return (s1);
}

static int	gnl_newline(char **save, char **line)
{
	int				i;
	char			*tmp;

	i = 0;
	while ((*save)[i] != '\n' && (*save)[i] != '\0')
		i++;
	if ((*save)[i] == '\n')
	{
		*line = ft_substr(*save, 0, i);
		tmp = ft_strdup(&(*save)[i + 1]);
		free(*save);
		*save = tmp;
	}
	else if ((*save)[i] == '\0')
	{
		*line = ft_strdup(*save);
		free(*save);
		*save = NULL;
		return (0);
	}
	return (1);
}

static int	gnl_compare(int br, int fd, char **sv, char **line)
{
	if (br < 0)
		return (-1);
	else if (br == 0 && sv[fd] == NULL)
	{
		*line = ft_strdup("");
		free(*sv);
		*sv = NULL;
		return (0);
	}
	else
		return (gnl_newline(&sv[fd], line));
}

int			get_next_line(int fd, char **line)
{
	char			*buffer;
	static char		*save[_SC_OPEN_MAX];
	char			*tmp;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || (!(buffer = malloc(sizeof(char)
			* (BUFFER_SIZE + 1)))))
		return (-1);
	while (((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0))
	{
		buffer[bytes_read] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strdup(buffer);
		else
		{
			tmp = gnl_strjoin(save[fd], buffer);
			free(save[fd]);
			save[fd] = tmp;
		}
		if (ft_strchr(save[fd], '\n'))
			break ;
	}
	free(buffer);
	buffer = NULL;
	return (gnl_compare(bytes_read, fd, save, line));
}
