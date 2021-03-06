/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:00:44 by mdesfont          #+#    #+#             */
/*   Updated: 2019/11/19 16:12:10 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char			*m;
	unsigned int	i;

	m = (char*)s;
	i = 0;
	while (i < n)
	{
		m[i] = '\0';
		i++;
	}
}
