/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:28:07 by mdesfont          #+#    #+#             */
/*   Updated: 2019/11/19 16:15:20 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char					*ptr;
	unsigned char			*m;
	unsigned char			*l;
	unsigned int			i;

	ptr = 0;
	m = (unsigned char*)dst;
	l = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		m[i] = l[i];
		if (l[i] == ((unsigned char)c))
		{
			ptr = dst + i + 1;
			return (ptr);
		}
		i++;
	}
	return (0);
}
