/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:57:39 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/22 21:11:49 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int		ft_obtain_ten(unsigned long long num)
{
	int ten;

	ten = 1;
	while ((num /= 10) > 0)
		ten++;
	return (ten);
}

static t_tab	*ft_do_u(t_tab *tab, unsigned long long num, int num_width)
{
	int			not_blank;

	not_blank = num_width;
	tab->left = 0;
	(tab->convert[0] == '-') ? tab->left = 1 : 0;
	if (num_width <= tab->precision)
		not_blank = tab->precision;
	tab->len += (not_blank <= tab->widht) ? tab->widht : not_blank;
	if (!tab->left)
		ft_display_widht(tab, ' ', tab->widht - not_blank, 0);
	ft_display_widht(tab, '0', tab->precision - num_width, 0);
	ft_putnbrul_fd(num, 1);
	if (tab->left)
		ft_display_widht(tab, ' ', tab->widht - not_blank, 0);
	return (tab);
}

static t_tab	*ft_space(t_tab *tab)
{
	if (tab->convert[0] != '-' && tab->widht == 0)
		ft_display_widht(tab, ' ', tab->widht, 1);
	if (tab->convert[0] != '-' && tab->widht != 0 && tab->precision > 0)
	{
		ft_display_widht(tab, ' ', tab->widht - 1, 1);
		ft_putchar('0');
	}
	if (tab->convert[0] == '-' && tab->widht != 0 && tab->precision == -1)
	{
		ft_putchar('0');
		ft_display_widht(tab, ' ', tab->widht - 1, 1);
		return (tab);
	}
	if (tab->convert[0] == '-')
	{
		tab->i--;
		ft_display_widht(tab, ' ', tab->widht, 1);
	}
	if (tab->precision == 0 && tab->widht > 0 && tab->convert[0] != '-')
	{
		ft_display_widht(tab, ' ', tab->widht, 0);
		return (tab);
	}
	return (tab);
}

t_tab			*ft_display_u(t_tab *tab)
{
	unsigned long long	num;
	int					num_width;

	num = (unsigned int)va_arg(tab->arg, unsigned int);
	if (num == 0 && tab->precision == -1 && tab->convert[6] != '.' &&
		tab->widht <= 0)
	{
		ft_putchar('0');
		return (tab);
	}
	num_width = ft_obtain_ten(num);
	if ((num == 0 && tab->precision == -1 && tab->widht <= 0) ||
		(num == 0 && tab->precision == 0))
	{
		if (tab->f_t[tab->i - 1] == 'u' && tab->convert[0] == '\0'
			&& tab->convert[3] == '\0')
			tab->i--;
		(tab->f_t[tab->i] == 'u' && tab->convert[0] == '-') ? tab->i++ : 0;
		ft_space(tab);
		return (tab);
	}
	if (tab->convert[3] == '0' && tab->precision == -1 && !tab->convert[0])
		tab->precision = tab->widht;
	ft_do_u(tab, num, num_width);
	return (tab);
}
