/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:58:41 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/29 11:11:15 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static unsigned long long	ft_get_num(t_tab *tab)
{
	unsigned long long	num;

	num = (unsigned long)(va_arg(tab->arg, unsigned long int));
	num = (unsigned long long)num;
	return (num);
}

static t_tab				*ft_do_p(t_tab *tab, char *str)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str) + 2;
	not_blank = num_width;
	tab->len += (not_blank <= tab->widht) ? tab->widht : not_blank;
	if (!tab->left)
		ft_display_widht(tab, ' ', tab->widht - not_blank, 0);
	write(tab->fd, "0x", 2);
	ft_display_widht(tab, '0', (tab->precision - num_width) + 2, 1);
	ft_putstr(str);
	if (tab->left)
		ft_display_widht(tab, ' ', tab->widht - not_blank, 0);
	free(str);
	return (tab);
}

static t_tab				*ft_numzero(t_tab *tab, unsigned long long num,
											char *str)
{
	int			num_width;

	num_width = ft_strlen(str) + 2;
	if (num == 0)
	{
		if (tab->precision == -1 && tab->convert[3] != '0')
			ft_display_widht(tab, ' ', (tab->widht - num_width), 0);
		if (tab->precision >= 0 || (tab->precision == -1 &&
			((tab->convert[3] == '0') || (tab->convert[6] == '.'))))
		{
			if (tab->precision == 0)
				ft_display_widht(tab, ' ', (tab->widht - 2), 0);
			write(tab->fd, "0x", 2);
			if (tab->precision > 0)
				ft_display_widht(tab, '0', tab->precision, 0);
			tab->l = 1;
			return (tab);
		}
		write(tab->fd, "0x0", 3);
		tab->l = 1;
		return (tab);
	}
	return (tab);
}

t_tab						*ft_display_p(t_tab *tab)
{
	char				*str;
	unsigned long long	num;

	tab->left = 0;
	num = ft_get_num(tab);
	str = ft_itoa_base(num, 16, 'a');
	if (tab->f_t[tab->i - 1] == 'p' && tab->convert[0] == '\0'
		&& tab->convert[3] == '\0')
		tab->i--;
	ft_numzero(tab, num, str);
	if (tab->l == 1)
	{
		free(str);
		return (tab);
	}
	tab->convert[0] == '-' ? tab->left = 1 : 0;
	if (tab->precision == 0 && num == 0)
		*str = '\0';
	if (tab->convert[3] == '0' && tab->precision == -1 && !tab->convert[0])
	{
		tab->precision = tab->widht - 2;
		tab->widht = 0;
	}
	ft_do_p(tab, str);
	return (tab);
}
