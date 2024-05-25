# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 04:01:12 by iqattami          #+#    #+#              #
#    Updated: 2024/05/25 04:03:20 by iqattami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = errors.c g_n_l.c so_long.c split.c utils.c

BONUS = 


OBJ = $(SRCS:.c=.o)
OBONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBONUS): $(BONUS)
	${CC} ${CFLAGS} -c ${BONUS}
		ar rc $(NAME) $(OBONUS)

bonus: $(OBONUS)
	

clean:
	rm -f $(OBJ) $(OBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all