/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:44:04 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/22 21:08:49 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_tab	*ft_parse_specifiers(t_tab *tab)
{
	size_t	i;

	i = 0;
	while (tab->specifiers[i] != '\0')
	{
		if (tab->specifiers[i] == tab->f_t[tab->i])
			tab->specifiers_flags = tab->specifiers[i];
		i++;
	}
	return (tab);
}
