/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:17:43 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/29 11:13:24 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void					ft_print_leading_zero(unsigned long long num,
												char hash, char x, int fd)
{
	if (num)
	{
		if (hash == '#' && x == 'x')
			write(fd, "0x", 2);
		if (hash == '#' && x == 'X')
			write(fd, "0X", 2);
	}
}

static unsigned long long	ft_get_num(t_tab *tab)
{
	unsigned long long	num;

	num = (unsigned int)(va_arg(tab->arg, unsigned int));
	num = (unsigned long long)num;
	return (num);
}

static t_tab				*ft_do_x(t_tab *tab, unsigned long long num,
													char *str)
{
	int			n_b;
	int			n_w;

	tab->left = 0;
	(tab->convert[0] == '-') ? tab->left = 1 : 0;
	if ((n_w = ft_strlen(str)) && tab->convert[4] == '#' && num &&
			tab->convert[3] == '0' && tab->widht)
		n_w += 2;
	else if ((n_w = ft_strlen(str)) && tab->convert[4] == '#' && num)
	{
		tab->widht -= 2;
		tab->len += 2;
	}
	n_b = (n_w <= tab->precision && tab->precision > 0) ? tab->precision : n_w;
	tab->len += (n_b <= tab->widht) ? tab->widht : n_b;
	if (!tab->left)
		ft_display_widht(tab, ' ', tab->widht - n_b, 0);
	ft_print_leading_zero(num, tab->convert[4], tab->specifiers_flags, tab->fd);
	ft_display_widht(tab, '0', tab->precision - n_w, 0);
	ft_putstr(str);
	if (tab->left)
		ft_display_widht(tab, ' ', tab->widht - n_b, 0);
	return (tab);
}

static t_tab				*ft_numzero(t_tab *tab, int num)
{
	if (num == 0 && tab->precision == 0)
	{
		if (tab->f_t[tab->i - 1] == 'x' || tab->f_t[tab->i - 1] == 'X')
			tab->i--;
		ft_display_widht(tab, ' ', tab->widht, 1);
		tab->k = 1;
		return (tab);
	}
	else
		return (tab);
}

t_tab						*ft_display_x(t_tab *tab)
{
	char				*str;
	char				c;
	unsigned long long	num;

	num = ft_get_num(tab);
	ft_numzero(tab, num);
	if (tab->k == 1)
		return (tab);
	c = 'a';
	(tab->specifiers_flags == 'X') ? c = 'A' : 0;
	str = ft_itoa_base(num, 16, c);
	(tab->f_t[tab->i - 1] == 'x' || tab->f_t[tab->i - 1] == 'X') ? tab->i-- : 0;
	if (((tab->precision < 0 && num == 0) && ((tab->convert[3] == '0' &&
			tab->convert[6] == '.') || (tab->convert[6] == '.'))))
	{
		free(str);
		return (tab);
	}
	if (tab->convert[3] == '0' && tab->precision == -1 && !tab->convert[0])
		tab->precision = tab->widht;
	ft_do_x(tab, num, str);
	(num == 0 || num == '\0') ? tab->len++ : 0;
	free(str);
	return (tab);
}
