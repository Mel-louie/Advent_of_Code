/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:56:28 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/22 21:08:49 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static t_tab	*ft_prec_just_num(t_tab *tab)
{
	while (tab->f_t[tab->i] >= '0' && tab->f_t[tab->i] <= '9')
	{
		tab->precision *= 10;
		tab->precision += (tab->f_t[tab->i] - 48);
		tab->i++;
	}
	return (tab);
}

static t_tab	*ft_num(t_tab *tab)
{
	if (tab->f_t[tab->i] >= '0' && tab->f_t[tab->i] <= '9')
	{
		ft_prec_just_num(tab);
		return (tab);
	}
	if (tab->f_t[tab->i + 1] == '.' && (tab->f_t[tab->i] >= '0'
				&& tab->f_t[tab->i] <= '9'))
	{
		while (tab->f_t[tab->i + 2] >= '0' && tab->f_t[tab->i + 2] <= '9')
		{
			tab->precision *= 10;
			tab->precision += (tab->f_t[tab->i + 2] - 48);
			tab->i++;
		}
		tab->i = tab->i + 2;
		return (tab);
	}
	else
	{
		tab->i++;
		if (tab->convert[6] == '.' &&
				(tab->f_t[tab->i] < '0' && tab->f_t[tab->i] > '9'))
			tab->i++;
		return (tab);
	}
}

static t_tab	*ft_dot(t_tab *tab)
{
	tab->i++;
	tab->precision = 0;
	if (tab->f_t[tab->i] == 's' || tab->f_t[tab->i] == 'c'
			|| tab->f_t[tab->i] == 'd' || tab->f_t[tab->i] == 'p'
			|| tab->f_t[tab->i] == 'x' || tab->f_t[tab->i] == 'X'
			|| tab->f_t[tab->i] == 'i' || tab->f_t[tab->i] == 'u')
		ft_parse_specifiers(tab);
	(tab->convert[0] == '-' && tab->f_t[tab->i - 1] != '.') ? tab->i -= 2 : 0;
	(tab->convert[0] != '-' && tab->f_t[tab->i - 1] != '.') ? tab->i -= 1 : 0;
	(tab->f_t[tab->i] == '*') ? tab->precision = tab->widht : 0;
	(tab->f_t[tab->i] == '*') ? tab->i++ : 0;
	(tab->convert[5] == '*' && tab->n == 1) ? tab->precision = tab->widht : 0;
	if (tab->convert[0] != '-' && tab->convert[5] == '*' &&
			(tab->f_t[tab->i] >= '0' && tab->f_t[tab->i] <= '9'))
	{
		while (tab->f_t[tab->i - 1] >= '0' && tab->f_t[tab->i - 1] <= '9')
			tab->i--;
		while (tab->f_t[tab->i] >= '0' && tab->f_t[tab->i] <= '9')
		{
			tab->precision *= 10;
			tab->precision += (tab->f_t[tab->i] - 48);
			tab->i++;
		}
	}
	return (tab);
}

t_tab			*ft_parse_precision(t_tab *tab)
{
	if ((tab->convert[6] == '.') || (tab->f_t[tab->i] == '.'))
	{
		ft_dot(tab);
		ft_num(tab);
	}
	if (tab->precision == 0 && tab->widht < 0)
		tab->precision = (-1);
	if (tab->p == 1)
		tab->precision = va_arg(tab->arg, int);
	return (tab);
}
