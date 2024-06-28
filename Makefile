# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 04:01:12 by iqattami          #+#    #+#              #
#    Updated: 2024/06/27 18:00:59 by iqattami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
NAME = so_long
RM = rm -f
SRCS = so_long.c split.c utils.c check_path.c window.c print_errors.c errors.c g_n_l.c utils1.c
OBJS = $(SRCS:.c=.o)
LIBS = libmlx.a  -L/usr/lib -lX11 -lXext

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re