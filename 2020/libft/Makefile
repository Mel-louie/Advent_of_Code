# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdesfont <mdesfont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 10:45:04 by mdesfont          #+#    #+#              #
#    Updated: 2020/09/22 21:06:14 by mdesfont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	./srcs/ft_atoi.c \
		./srcs/ft_bzero.c \
		./srcs/ft_isalnum.c \
		./srcs/ft_isalpha.c \
		./srcs/ft_isascii.c \
		./srcs/ft_isdigit.c \
		./srcs/ft_isprint.c \
		./srcs/ft_isupper.c \
		./srcs/ft_memccpy.c \
		./srcs/ft_memchr.c \
		./srcs/ft_memcmp.c \
		./srcs/ft_memcpy.c \
		./srcs/ft_memmove.c \
		./srcs/ft_memset.c \
		./srcs/ft_strchr.c \
		./srcs/ft_strdup.c \
		./srcs/ft_strndup.c \
		./srcs/ft_strjoin.c \
		./srcs/ft_strlcpy.c \
		./srcs/ft_strlen.c \
		./srcs/ft_strcmp.c \
		./srcs/ft_strncmp.c \
		./srcs/ft_strnstr.c \
		./srcs/ft_strrchr.c \
		./srcs/ft_substr.c \
		./srcs/ft_tolower.c \
		./srcs/ft_toupper.c \
		./srcs/ft_strlcat.c \
		./srcs/ft_calloc.c \
		./srcs/ft_split.c \
		./srcs/ft_itoa.c \
		./srcs/ft_itoa_base.c \
		./srcs/ft_utoa.c \
		./srcs/ft_strmapi.c \
		./srcs/ft_putchar.c \
		./srcs/ft_putchar_fd.c \
		./srcs/ft_putstr.c \
		./srcs/ft_putstr_fd.c \
		./srcs/ft_putendl.c \
		./srcs/ft_putendl_fd.c \
		./srcs/ft_putnbr.c \
		./srcs/ft_putnbr_fd.c \
		./srcs/ft_putnbrl_fd.c \
		./srcs/ft_putnbrul_fd.c \
		./srcs/ft_strtrim.c \
		./srcs/ft_lstnew_bonus.c \
		./srcs/ft_lstsize_bonus.c \
		./srcs/ft_lstdelone_bonus.c \
		./srcs/ft_strcpy.c \
		./srcs/get_next_line_fd0.c \
		./srcs/get_next_line_multifd.c \
		./srcs/ft_get_digit.c \
		./srcs/gt_putnbr_base.c \
		./srcs/ft_printf/ft_display_.c \
		./srcs/ft_printf/ft_display_c.c \
		./srcs/ft_printf/ft_display_d.c \
		./srcs/ft_printf/ft_display_p.c \
		./srcs/ft_printf/ft_display_s.c \
		./srcs/ft_printf/ft_display_u.c \
		./srcs/ft_printf/ft_display_widht.c \
		./srcs/ft_printf/ft_display_x.c \
		./srcs/ft_printf/ft_initialize.c \
		./srcs/ft_printf/ft_parse_converts.c \
		./srcs/ft_printf/ft_parse_precision.c \
		./srcs/ft_printf/ft_parse_specifiers.c \
		./srcs/ft_printf/ft_parse_widht.c \
		./srcs/ft_printf/ft_parser.c \
		./srcs/ft_printf/ft_printf.c \
		./srcs/ft_printf/ft_send_displays.c \
		./srcs/ft_printf/ft_treatments.c \
		./srcs/ft_printf/ft_reinitialize.c \
		./srcs/ft_printf/ft_prec_and_width.c \


OBJ = $(SRC:.c=.o)

Ctab = -Wall -Wextra -Werror
NAME = libft.a

CC = gcc

.c.o::
		$(CC) $(Ctab) -c $< -o $(<:.c=.o)

$(NAME)::	$(OBJ)
			ar -rc $(NAME) $(OBJ)

all:		$(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
