# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 18:17:45 by kilchenk          #+#    #+#              #
#    Updated: 2023/03/16 17:00:06 by kilchenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIB_F = inc/Libft
LIB = libft.a
SRC = src
OBJ = obj
INC = inc
CFLAGS = -g -I$(INC) -Wall -Wextra -Werror
RM = rm -rf
CC = gcc
SRCS =	src/push_swap/push_swap.c					\
		src/push_swap/push_swap_utils.c				\
		src/push_swap/input_check.c					\
		src/push_swap/parsing.c						\
		src/push_swap/stacks.c						\
		src/push_swap/push_op.c						\
		src/push_swap/swap_op.c						\
		src/push_swap/rotate_op.c					\
		src/push_swap/rev_rot_op.c					\
		src/push_swap/utils.c						\
		src/push_swap/sorts.c						\
		src/push_swap/calc.c						\
		src/push_swap/calc_utils.c					\
		

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[92m.\033[0m\c"

$(NAME): $(OBJS) $(LIB_F)/$(LIB)
	@$(CC) $(CFLAGS) $(OBJS) src/push_swap/main.c $(LIB_F)/$(LIB) -o $(NAME)
# @echo "\033[92m.\033[0m\c"


$(LIB_F)/$(LIB):
	@make -C $(LIB_F)
	@echo "\n\033[92mPush_swap successfully compiled!\033[0m"
	@bash minion.sh

clean:
	@$(RM) $(OBJS) src/checker/checker.o
	@rm -rf obj 
	@echo "\033[0;31mPush_swap successfully cleaned!\033[0m"

fclean: clean
	@$(RM) $(NAME) checker
	@make fclean -C $(LIB_F)

re: fclean all

bonus: $(OBJS) $(LIB_F)/$(LIB)
	@$(CC) $(CFLAGS) $(OBJS) src/checker/checker.c $(LIB_F)/$(LIB) -o checker