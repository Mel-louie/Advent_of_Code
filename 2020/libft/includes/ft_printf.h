/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:32:57 by mdesfont          #+#    #+#             */
/*   Updated: 2020/09/29 11:17:59 by mdesfont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft.h"

typedef struct	s_tab
{
	const char	*format;
	char		*f_copy;
	char		*f_t;
	va_list		arg;
	int			len;
	int			i;
	char		*specifiers;
	char		specifiers_flags;
	char		*converters;
	char		convert[7];
	long int	widht;
	long int	precision;
	int			j;
	int			k;
	int			l;
	int			m;
	int			n;
	int			o;
	int			p;
	char		*dup;
	int			left;
	int			fd;
}				t_tab;

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
t_tab			*ft_initialize(t_tab *tab);
int				ft_parsers(t_tab *tab);
t_tab			*ft_reinitialize(t_tab *tab);
t_tab			*ft_parse_converts(t_tab *tab);
t_tab			*ft_parse_converts2(t_tab *tab);
t_tab			*ft_parse_specifiers(t_tab *tab);
int				ft_treatments(t_tab *tab);
t_tab			*ft_send_displays(t_tab *tab);
t_tab			*ft_parse_widht(t_tab *tab);
t_tab			*ft_display_c(t_tab *tab);
t_tab			*ft_display_d(t_tab *tab);
t_tab			*ft_display_u(t_tab *tab);
int				ft_display_widht(t_tab *tab, char c, int len, int update_len);
t_tab			*ft_display_s(t_tab *tab);
t_tab			*ft_display_x(t_tab *tab);
t_tab			*ft_display_p(t_tab *tab);
t_tab			*ft_display_(t_tab *tab);
t_tab			*ft_parse_precision(t_tab *tab);
t_tab			*ft_prec_and_width(t_tab *tab, long long num, char sign_place);
#endif
