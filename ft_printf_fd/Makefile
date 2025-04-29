# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkorzec <gkorzecz@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 17:19:24 by gkorzec           #+#    #+#              #
#    Updated: 2025/04/21 13:23:35 by gkorzecz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = ft_printchar_fd.c ft_printstr_fd.c ft_printf_fd.c ft_printhex_fd.c ft_printnbr_fd.c ft_printunsi_fd.c ft_printptr_fd.c

SRCS = $(CFILES)

OFILES = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf_fd.a

all: $(NAME)

$(NAME): $(OFILES)
	@ar -rcs $(NAME) $(OFILES)
clean:
	@rm -f $(OFILES)

fclean:clean
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
