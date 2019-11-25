# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 16:41:53 by ubartemi          #+#    #+#              #
#    Updated: 2019/05/15 17:04:53 by aestella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = algorithm.c fillit.c map.c validation.c validation2.c

OBJ = $(SRC:.c=.o) 

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	cd ./libft && make
	gcc -c -Wextra -Wall -Werror $(SRC)
	gcc $(OBJ) libft/libft.a -I libft -o $(NAME)

clean:
	rm -f $(OBJ)
	cd ./libft && make clean

fclean: clean
	rm -f $(NAME)
	cd ./libft && make fclean

re: fclean all
