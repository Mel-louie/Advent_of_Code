/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:20:15 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/21 12:19:20 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char *m;
	char *l;

	if ((dst == NULL) && (src == NULL))
		return (0);
	m = (char *)dst;
	l = (char *)src;
	if (dst > src)
	{
		while (len > 0)
		{
			m[len - 1] = l[len - 1];
			len--;
		}
		return (dst);
	}
	else
		while (len > 0)
		{
			*m = *l;
			m++;
			l++;
			len--;
		}
	return (dst);
}
