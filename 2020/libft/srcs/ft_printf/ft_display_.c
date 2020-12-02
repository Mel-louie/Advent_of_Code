/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:50:18 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/29 11:11:15 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static t_tab	*ft_percent(t_tab *tab)
{
	if (tab->convert[3] == '0' && tab->precision <= 0 && !tab->convert[0])
	{
		tab->precision = tab->widht;
		tab->widht = 0;
	}
	if (tab->convert[0] != '-')
		ft_display_widht(tab, ' ', tab->widht - 1, 1);
	if (tab->convert[3] == '0')
		ft_display_widht(tab, '0', tab->precision - 1, 1);
	write(tab->fd, "%", 1);
	if (tab->convert[0] == '-')
		ft_display_widht(tab, ' ', tab->widht - 1, 1);
	tab->len++;
	return (tab);
}

t_tab			*ft_display_(t_tab *tab)
{
	if (tab->f_t[tab->i] == '%')
	{
		ft_percent(tab);
		return (tab);
	}
	if (tab->convert[3] == '0' && tab->precision <= 0 && !tab->convert[0])
	{
		tab->precision = tab->widht;
		tab->widht = 0;
	}
	if (tab->convert[0] != '-')
		ft_display_widht(tab, ' ', tab->widht - 1, 1);
	if (tab->convert[3] == '0')
		ft_display_widht(tab, '0', tab->precision - 1, 1);
	write(tab->fd, &tab->f_copy[tab->i], 1);
	if (tab->convert[0] == '-')
		ft_display_widht(tab, ' ', tab->widht - 1, 1);
	tab->len++;
	return (tab);
}
