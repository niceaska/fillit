# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/15 15:08:42 by gwyman-m          #+#    #+#              #
#    Updated: 2019/04/15 18:15:51 by gwyman-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

LIBFT = -L libft/ -lft

SRC = main.c checking.c free.c list.c move.c print.c read.c solve.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) tetris.h
	make -C libft
	gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(SRC)
	gcc $(FLAGS) -c $(SRC) -I libft/includes

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
