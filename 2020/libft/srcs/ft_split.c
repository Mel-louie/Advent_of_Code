/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:42:19 by mdesfont          #+#    #+#             */
/*   Updated: 2019/11/19 16:20:25 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_countwords(const char *str, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			word++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (word);
}

char		**ft_split(const char *str, char c)
{
	int		i;
	int		j;
	char	**s;
	int		k;

	i = 0;
	k = 0;
	if (str == NULL)
		return (NULL);
	if (!(s = (char **)malloc(sizeof(s) * (ft_countwords(str, c) + 1))))
		return (0);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		j = i;
		while (str[i] && str[i] != c)
			i++;
		if (i > j)
			s[k++] = ft_strndup(str + j, i - j);
	}
	s[k] = 0;
	return (s);
}
