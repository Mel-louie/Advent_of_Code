/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:35:27 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/29 11:11:15 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int		ft_obtain_ten(long long num)
{
	int ten;

	if (num < 0)
		num *= -1;
	ten = 1;
	while ((num /= 10) > 0)
		ten++;
	return (ten);
}

static char		ft_placesign(int is_negative)
{
	if (is_negative)
		return ('-');
	return ('\0');
}

static t_tab	*ft_displayzero(t_tab *tab, int sign_place, int num_width)
{
	if (tab->convert[3] == '0' && sign_place && (tab->precision < tab->widht))
	{
		ft_display_widht(tab, '0', tab->precision - num_width, 0);
		return (tab);
	}
	if (tab->convert[3] == '0' && sign_place && (tab->precision > tab->widht))
	{
		ft_display_widht(tab, '0', tab->precision - num_width, 0);
		return (tab);
	}
	if (tab->convert[3] == '0' && sign_place && tab->precision == tab->widht)
	{
		ft_display_widht(tab, '0', tab->precision - num_width - 1, 0);
		return (tab);
	}
	if (tab->convert[3] == '0' && !sign_place)
	{
		ft_display_widht(tab, '0', tab->precision - num_width, 0);
		return (tab);
	}
	else
		ft_display_widht(tab, '0', tab->precision - num_width, 0);
	return (tab);
}

static t_tab	*ft_do_d(t_tab *tab, long long num, int num_width)
{
	int			not_blank;
	char		sign_place;
	int			negative;

	negative = (num < 0) ? 1 : 0;
	num *= (negative && num != (-2147483648 - 1)) ? -1 : 1;
	sign_place = ft_placesign(negative);
	not_blank = num_width;
	if (num_width <= tab->precision && tab->precision >= 0)
		not_blank = tab->precision;
	sign_place ? not_blank++ : 0;
	tab->len += (not_blank <= tab->widht) ? tab->widht : not_blank;
	if (tab->convert[5] == '*' && tab->convert[6] == '.' && tab->precision == 0)
		ft_prec_and_width(tab, num, sign_place);
	if (tab->m == 1)
		return (tab);
	(!tab->left) ? ft_display_widht(tab, ' ', tab->widht - not_blank, 0) : 0;
	(sign_place) ? write(tab->fd, &sign_place, 1) : 0;
	ft_displayzero(tab, sign_place, num_width);
	if (num != (-2147483648 - 1))
		ft_putnbrl_fd(num, 1);
	else if ((tab->len += 9) > 0)
		write(tab->fd, "2147483648", 10);
	(tab->left) ? ft_display_widht(tab, ' ', tab->widht - not_blank, 0) : 0;
	return (tab);
}

t_tab			*ft_display_d(t_tab *tab)
{
	long long	num;
	int			num_width;

	num = (int)(va_arg(tab->arg, int));
	if (num == 0 && tab->precision == 0)
	{
		if (tab->f_t[tab->i - 1] == 'i' || tab->f_t[tab->i - 1] == 'd')
			tab->i--;
		ft_display_widht(tab, ' ', tab->widht, 1);
		return (tab);
	}
	(tab->f_t[tab->i - 1] == 'i' || tab->f_t[tab->i - 1] == 'd') ? tab->i-- : 0;
	if (((tab->precision < 0 && num == 0) && ((tab->convert[3] == '0' &&
			tab->convert[6] == '.') || (tab->convert[6] == '.'))))
	{
		tab->dup = ft_strdup("");
		free(tab->dup);
		return (tab);
	}
	num_width = ft_obtain_ten(num);
	tab->left = (tab->convert[0] == '-') ? 1 : 0;
	if (tab->convert[3] == '0' && tab->precision == -1 && !tab->convert[0])
		tab->precision = tab->widht;
	ft_do_d(tab, num, num_width);
	return (tab);
}
