/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:18:40 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/29 11:26:57 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_tab *tab;

	if (!(tab = (t_tab*)malloc(sizeof(t_tab))))
		return (-1);
	tab->fd = 1;
	tab->format = format;
	tab = ft_initialize(tab);
	if (format)
	{
		va_start(tab->arg, format);
		tab->len = ft_parsers(tab);
		va_end(tab->arg);
	}
	free(tab);
	return (tab->len);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	t_tab *tab;

	if (!(tab = (t_tab*)malloc(sizeof(t_tab))))
		return (-1);
	tab->fd = fd;
	tab->format = format;
	tab = ft_initialize(tab);
	if (format)
	{
		va_start(tab->arg, format);
		tab->len = ft_parsers(tab);
		va_end(tab->arg);
	}
	free(tab);
	return (tab->len);
}
