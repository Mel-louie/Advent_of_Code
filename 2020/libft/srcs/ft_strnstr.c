/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:21:31 by mdesfont          #+#    #+#             */
/*   Updated: 2019/11/19 16:24:37 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned char	i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return (char*)haystack;
	while (i < len)
	{
		if (ft_strncmp((char*)&haystack[i], needle, ft_strlen(needle)) == 0)
		{
			if (i + ft_strlen(needle) > len)
				return (0);
			return ((char*)haystack + i);
		}
		i++;
	}
	return (0);
}
