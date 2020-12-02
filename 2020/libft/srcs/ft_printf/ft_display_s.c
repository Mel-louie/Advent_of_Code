/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:06:33 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/22 21:08:49 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static t_tab	*ft_dos(t_tab *tab, char *s, int len)
{
	if (tab->convert[3] == '0' && tab->convert[0] != '-')
		ft_display_widht(tab, '0', tab->widht - len, 1);
	else if (tab->convert[6] == '.' && tab->precision < tab->widht)
	{
		ft_putstr(s);
		if (tab->convert[0] == '-')
			ft_display_widht(tab, ' ', tab->widht - len, 1);
		if (tab->precision > -1 || tab->precision == -1)
			free(s);
		return (tab);
	}
	else if (tab->convert[0] != '-')
		ft_display_widht(tab, ' ', tab->widht - len, 1);
	ft_putstr(s);
	if (tab->convert[0] == '-')
		ft_display_widht(tab, ' ', tab->widht - len, 1);
	if (tab->precision > -1 || tab->precision == -1)
		free(s);
	return (tab);
}

t_tab			*ft_display_s(t_tab *tab)
{
	char		*s;
	int			len;

	if (tab->f_t[tab->i - 1] == 's')
		tab->i--;
	s = va_arg(tab->arg, char *);
	if (tab->precision > -1 && s)
		s = ft_strndup(s, tab->precision);
	else if (tab->precision == -1 && s)
		s = ft_strdup(s);
	else if (tab->precision > -1 && !s)
		s = ft_strndup("(null)", tab->precision);
	else if (tab->precision == -1 && !s)
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	tab->len += len;
	ft_dos(tab, s, len);
	return (tab);
}
