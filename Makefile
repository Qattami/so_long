# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 04:01:12 by iqattami          #+#    #+#              #
#    Updated: 2024/05/31 15:38:18 by iqattami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = so_long
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
SOURCES =  errors.c g_n_l.c so_long.c split.c utils.c check_path.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)
$(NAME) :$(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) $(MLX_FLAGS) -o $(NAME)
	
clean :
	rm -rf $(OBJECTS)
fclean : clean
		rm -rf $(NAME)
re : fclean all