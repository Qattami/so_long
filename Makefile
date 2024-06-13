# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 04:01:12 by iqattami          #+#    #+#              #
#    Updated: 2024/06/13 20:58:11 by iqattami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CC = cc
# NAME = so_long
# FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
# MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
# SOURCES =  errors.c g_n_l.c so_long.c split.c utils.c check_path.c

# OBJECTS = $(SOURCES:.c=.o)

# all : $(NAME)
# $(NAME) :$(OBJECTS)
# 	$(CC) $(FLAGS) $(OBJECTS) $(MLX_FLAGS) -o $(NAME)
	
# clean :
# 	rm -rf $(OBJECTS)
# fclean : clean
# 		rm -rf $(NAME)
# re : fclean all


NAME = so_long
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lXext -lX11 -lm 

SOURCES = errors.c g_n_l.c so_long.c split.c utils.c check_path.c window.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) :$(OBJECTS)
	$(CC) $(FLAGS) $^ $(MLX_FLAGS) -o $@
    
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@    

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all