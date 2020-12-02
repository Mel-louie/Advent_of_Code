/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_widht.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:24:42 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/29 11:11:15 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_display_widht(t_tab *tab, char c, int len, int update_len)
{
	char	*str;

	if (len > 0)
	{
		if (update_len)
			tab->len += len;
		if (!(str = malloc(sizeof(char *) * len + 1)))
			return (-1);
		ft_memset(str, c, len);
		write(tab->fd, str, len);
		free(str);
	}
	return (tab->len);
}
