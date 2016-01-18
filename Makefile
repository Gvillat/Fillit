# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppetit <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/18 17:13:04 by ppetit            #+#    #+#              #
#    Updated: 2016/01/18 17:14:56 by ppetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

SRC_PATH = ./sources/
SRC_NAME =	check_tetris.c\
			createmap.c\
			points_assignment.c\
			backtrack.c\
			main.c\
			open_file.c

OBJ = $(SRC_NAME:.c=.o) $(TEST_NAME:.c=.o) $(LIB_NAME:.c=.o)

LIB_PATH = ./lib/
LIB_NAME = 	ft_putstr.c\
			ft_putchar.c\
			ft_putnbr.c\
			ft_sqrt.c\
			ft_strlen.c\
			ft_round.c\
			ft_memset.c\
			ft_strsetnew.c\
			ft_abs.c

INC_PATH = ./includes/
INC_NAME = fillit.h\

NAME = fillit

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))
INC = $(addprefix $(INC_PATH),$(INC_NAME))

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) $(LIB) -I $(INC) -o $(NAME)
	@echo "\033[1;33mCompilation \t \033[0;32m[OK]\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "\033[1;33mCleaning obj \t \033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1;33mCleaning exec \t \033[0;32m[OK]\033[0m"

re: fclean all

norme:
	@norminette $(SRC)
	@norminette $(LIB)
	@echo "\033[1;33mNorminette check \033[0;32m[OK]\033[0m"
