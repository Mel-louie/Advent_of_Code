/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrul_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 21:26:14 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/22 21:26:16 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbrul_fd(unsigned long long n, int fd)
{
	if (n > 9)
		ft_putnbrul_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}
