/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:16:49 by mdesfont          #+#    #+#             */
/*   Updated: 2020/02/24 11:29:19 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	len_s1;
	char	*tmp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	tmp = ft_strdup(s1);
	free(s1);
	if (!(s1 = malloc(sizeof(char) * (len_s1 + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(s1, tmp);
	free(tmp);
	ft_strcpy(s1 + len_s1, s2);
	return (s1);
}
