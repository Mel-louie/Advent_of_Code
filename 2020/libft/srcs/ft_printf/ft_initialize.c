/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 13:15:56 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/22 21:08:49 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_tab	*ft_initialize(t_tab *tab)
{
	tab->len = 0;
	tab->i = 0;
	tab->j = 0;
	tab->k = 0;
	tab->l = 0;
	tab->n = 0;
	tab->o = 0;
	tab->p = 0;
	tab->specifiers = "scdiuxXpn%";
	tab->converters = "-+ 0#.*";
	tab->f_t = (char *)tab->format;
	tab->f_copy = (char *)tab->format;
	return (tab);
}
