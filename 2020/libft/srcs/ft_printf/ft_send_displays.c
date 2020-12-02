/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_displays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:15:15 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/22 21:08:49 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void		ft_printlen(t_tab *tab)
{
	*va_arg(tab->arg, int *) = tab->len;
}

t_tab			*ft_send_displays(t_tab *tab)
{
	char	*flag;

	flag = &tab->specifiers_flags;
	if (*flag == 'd' || *flag == 'i')
		ft_display_d(tab);
	else if (*flag == 'c')
		ft_display_c(tab);
	else if (*flag == 's')
		ft_display_s(tab);
	else if (*flag == 'u')
		ft_display_u(tab);
	else if (*flag == 'x' || *flag == 'X')
		ft_display_x(tab);
	else if (*flag == 'n')
		ft_printlen(tab);
	else if (*flag == 'p')
		ft_display_p(tab);
	else
		ft_display_(tab);
	return (tab);
}
