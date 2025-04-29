# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkorzecz <gkorzec@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 13:34:41 by gkorzecz          #+#    #+#              #
#    Updated: 2025/04/21 13:37:10 by gkorzecz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = get_next_line.c get_next_line_utils.c

SRCS = $(CFILES)

OFILES = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = get_next_line.a

all: $(NAME)

$(NAME): $(OFILES)
	@ar -rcs $(NAME) $(OFILES)
clean:
	@rm -f $(OFILES)

fclean:clean
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus

