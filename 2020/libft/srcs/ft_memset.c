/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:10:22 by mdesfont          #+#    #+#             */
/*   Updated: 2019/11/19 16:16:24 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char			*m;
	unsigned int	i;

	m = (char*)s;
	i = 0;
	while (i < n)
	{
		m[i] = (char)c;
		i++;
	}
	return (s);
}
