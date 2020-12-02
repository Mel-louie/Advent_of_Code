/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:04:38 by mdesfont          #+#    #+#             */
/*   Updated: 2019/11/19 16:23:13 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned char	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = ft_strlen(dst);
	while (dst[j] && j < dstsize)
		j++;
	if (!(j < dstsize))
		return (dstsize + ft_strlen(src));
	while (src[i] && i < (dstsize - k - 1))
	{
		dst[j + i] = ((char*)src)[i];
		i++;
	}
	dst[j + i] = '\0';
	return (j + ft_strlen(src));
}
