/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:03:40 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/22 21:08:49 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static t_tab	*ft_direct_dot(t_tab *tab)
{
	ft_parse_specifiers(tab);
	ft_send_displays(tab);
	return (tab);
}

static t_tab	*ft_sparks(t_tab *tab)
{
	if (tab->f_t[tab->i + 1] == '.' && tab->f_t[tab->i] == '*')
	{
		tab->j = 1;
		ft_parse_converts(tab);
		ft_parse_widht(tab);
		ft_parse_precision(tab);
		if ((tab->f_t[tab->i - 1] == 'd' || tab->f_t[tab->i - 1] == 'i' ||
			tab->f_t[tab->i - 1] == 'u' || tab->f_t[tab->i - 1] == 'x' ||
			tab->f_t[tab->i - 1] == 'X' || tab->f_t[tab->i - 1] == 'p' ||
			tab->f_t[tab->i - 1] == 's') && tab->precision > 0)
		{
			tab->i--;
			ft_display_widht(tab, ' ', tab->widht - tab->precision, 1);
		}
		ft_parse_specifiers(tab);
		ft_send_displays(tab);
	}
	return (tab);
}

static t_tab	*ft_jzero(t_tab *tab)
{
	ft_parse_converts(tab);
	ft_parse_widht(tab);
	ft_parse_precision(tab);
	ft_parse_specifiers(tab);
	ft_send_displays(tab);
	return (tab);
}

int				ft_treatments(t_tab *tab)
{
	tab->i++;
	if (tab->f_t[tab->i] == '.' && tab->f_t[tab->i + 1] != '*')
	{
		ft_parse_converts(tab);
		if (tab->f_t[tab->i] == 'd' || tab->f_t[tab->i] == 'i' ||
			tab->f_t[tab->i] == 'u' || tab->f_t[tab->i] == 'x' ||
			tab->f_t[tab->i] == 'X' || tab->f_t[tab->i] == 'p')
		{
			ft_direct_dot(tab);
			return (tab->len);
		}
		ft_parse_precision(tab);
		ft_parse_specifiers(tab);
		ft_send_displays(tab);
		return (tab->len);
	}
	ft_sparks(tab);
	if (tab->j == 0)
		ft_jzero(tab);
	return (tab->len);
}
