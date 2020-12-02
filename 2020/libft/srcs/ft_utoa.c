/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:46:49 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/21 12:20:42 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_utoa(unsigned long n)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (0);
	if (n == 4294967295)
		return (ft_strdup("4294967295"));
	if (n == 0)
		return (ft_strdup("0"));
	else if (n >= 10)
		str = ft_strjoin(ft_utoa(n / 10), ft_utoa(n % 10));
	else if (n < 10)
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}
