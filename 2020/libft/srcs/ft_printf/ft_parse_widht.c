/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_widht.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:10:44 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/22 21:08:49 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_tab	*ft_parse_widht(t_tab *tab)
{
	if (tab->convert[5] == '*')
	{
		tab->widht = va_arg(tab->arg, int);
		if (tab->widht < 0 && tab->convert[6] != '.')
		{
			tab->widht *= (-1);
			tab->convert[0] = '-';
		}
		ft_parse_specifiers(tab);
		(tab->convert[0] == '-') ? tab->i = tab->i + 1 : 0;
	}
	else if (tab->f_t[tab->i] >= '0' && tab->f_t[tab->i] <= '9')
	{
		if (tab->f_t[tab->i - 1] == '0' && tab->f_t[tab->i - 2] == '.')
			return (tab);
		while (tab->f_t[tab->i] >= '0' && tab->f_t[tab->i] <= '9')
		{
			tab->widht *= 10;
			tab->widht += (tab->f_t[tab->i] - 48);
			tab->i++;
		}
	}
	if (tab->widht < 0 && tab->p == 1)
		tab->widht *= (-1);
	return (tab);
}
