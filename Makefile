# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubartemi <ubartemi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 16:41:53 by ubartemi          #+#    #+#              #
#    Updated: 2019/05/14 00:47:25 by ubartemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = 	./src/fillit.c ./src/algorithm.c ./src/validation.c \
		./src/validation2.c ./src/map.c ./src/ft_memset.c \
		./src/ft_putstr.c ./src/ft_strdup.c ./src/ft_strnew.c \
		./src/ft_putchar.c ./src/ft_strdel.c ./src/ft_strlen.c ./src/ft_strsub.c
INCL = ./includes
OBJ = ./fillit.o ./algorithm.o ./validation.o \
		./validation2.o ./map.o ./ft_memset.o \
		./ft_putstr.o ./ft_strdup.o ./ft_strnew.o \
		./ft_putchar.o ./ft_strdel.o ./ft_strlen.o ./ft_strsub.o

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC) 
	@gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -I $(INCL)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
