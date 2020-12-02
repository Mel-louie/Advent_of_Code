/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_converts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:59:11 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/22 21:08:49 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static t_tab	*ft_parse_stardotstar(t_tab *tab)
{
	if (tab->f_t[tab->i] == '.' && (!ft_isdigit(tab->f_t[tab->i + 1])) &&
			tab->f_t[tab->i - 1] == '*')
		tab->p = 1;
	if (tab->f_t[tab->i] == '.' && tab->f_t[tab->i + 1] == '*' &&
			tab->convert[5] != '*')
		tab->n = 1;
	return (tab);
}

static t_tab	*ft_parse(size_t i, t_tab *tab)
{
	while (tab->converters[i] != '\0')
	{
		ft_parse_stardotstar(tab);
		while (tab->converters[i] == tab->f_t[tab->i])
		{
			while (tab->f_t[tab->i] == '-' && tab->i++)
				tab->convert[0] = '-';
			while (tab->f_t[tab->i] == '+' && tab->i++)
				tab->convert[1] = '+';
			while (tab->f_t[tab->i] == ' ' && tab->i++)
				tab->convert[2] = ' ';
			while (tab->f_t[tab->i] == '0' && tab->i++)
				tab->convert[3] = '0';
			while (tab->f_t[tab->i] == '#' && tab->i++)
				tab->convert[4] = '#';
			while (tab->f_t[tab->i] == '.' && tab->i++)
				tab->convert[6] = '.';
			while ((tab->f_t[tab->i] == '*' && tab->i++) &&
					tab->convert[5] != '*')
				tab->convert[5] = '*';
			i = 0;
		}
		i++;
	}
	return (tab);
}

t_tab			*ft_parse_converts(t_tab *tab)
{
	size_t	i;

	i = 0;
	ft_parse(i, tab);
	return (tab);
}
