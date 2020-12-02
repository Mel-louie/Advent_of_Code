/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:10:01 by mdesfont          #+#    #+#             */
/*   Updated: 2019/11/19 16:25:06 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*trimed;
	char	*m;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	m = (char*)s1;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	len = ft_strlen(&s1[i]);
	if (len != 0)
		while (s1[i + len - 1]
				&& ft_strchr(set, s1[i + len - 1]) != NULL)
			len--;
	if (!(trimed = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	trimed = ft_strncpy(trimed, &m[i], len);
	trimed[len] = '\0';
	return (trimed);
}
