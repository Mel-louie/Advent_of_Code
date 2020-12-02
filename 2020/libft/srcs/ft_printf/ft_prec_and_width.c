/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_and_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:42:13 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/29 11:11:15 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_tab	*ft_prec_and_width(t_tab *tab, long long num, char sign_place)
{
	(sign_place) ? write(tab->fd, &sign_place, 1) : 0;
	if (tab->convert[5] == '*' && tab->convert[6] == '.' && tab->precision == 0)
	{
		ft_display_widht(tab, '0', tab->widht -
				(ft_strlen(ft_itoa(num))), 0);
		if (num != (-2147483648 - 1))
			ft_putnbrl_fd(num, 1);
		else if ((tab->len += 9) > 0)
			write(tab->fd, "2147483648", 10);
		tab->m = 1;
	}
	return (tab);
}
