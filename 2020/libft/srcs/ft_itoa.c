/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:49:34 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/22 11:27:09 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	num_len(long int n)
{
	if (n < 0)
		n = -n;
	if (n >= 10)
		return (1 + num_len(n / 10));
	return (1);
}

static void		set_str(char *str, long int n, int len)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i++;
	}
	while (i <= len)
	{
		str[len] = (n % 10) + '0';
		n = (n / 10);
		len--;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len_n;

	len_n = num_len(n);
	if (n < 0)
		len_n++;
	if (!(str = ft_calloc(len_n + 1, sizeof(char))))
		return (0);
	set_str(str, n, len_n - 1);
	free(str);
	return (str);
}
