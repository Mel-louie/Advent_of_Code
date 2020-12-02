/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_fd0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:34:49 by mdesfont          #+#    #+#             */
/*   Updated: 2020/02/24 12:46:26 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		get_next_line_fd0(char **line)
{
	static char	buffer[1];
	int			ret;

	if (!line)
		return (-1);
	*line = ft_strdup("");
	while ((ret = read(0, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n')
			return (1);
		if ((*line = ft_strjoin(*line, buffer)) == NULL)
			return (-1);
	}
	if (ret < 0)
		return (-1);
	return (ret);
}
