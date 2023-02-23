# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 18:17:45 by kilchenk          #+#    #+#              #
#    Updated: 2023/02/23 19:56:30 by kilchenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	src/push_swap/push_swap.c					\
		src/push_swap/main.c						\
		src/push_swap/push_swap_utilis.c			\
		src/push_swap/input_check.c					\
		src/push_swap/parsing.c						\
		src/push_swap/stacks.c						\
		src/push_swap/push_op.c						\
		src/push_swap/swap_op.c						\
		src/push_swap/rotate_op.c					\
		src/push_swap/rev_rot_op.c					\
		src/push_swap/utils.c						\

OBJ_DIR = obj/
		
OBJ =	$(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
MV = mv

LIBFT =	inc/Libft/libft.a

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[92m.\033[0m\c"

$(NAME): $(OBJ) $(SRC)
	@$(MAKE) -C Libft
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	@echo "\033[92mPush_swap successfully compiled!\033[0m"

clean:
	@$(MAKE) fclean -C Libft
	@$(RM) $(OBJ) 
	@echo "\033[0;31mPush_swap successfully cleaned!\033[0m"
fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


# SRCS =	push_swap.c					\
# 		swap.c						\
	
# SRC_MAIN = main.c

# NAME = push_swap

# LIBFT = inc/libft/

# OBJ_DIR = obj/
# SRC_DIR = src/push_swap/

# OBJ = $(SRC:.c=.o)
# OBJ_MAIN = $(SRC_MAIN:.c=.o)
# OBJ_PREFIX = $(addprefix $(OBJ_DIR), $(OBJ))
# OBJ_MAIN_PREFIX = $(addprefix $(OBJ_DIR), $(OBJ_MAIN))
# SRC_PREFIX = $(addprefix $(SRC_DIR), $(SRC))
# SRC_MAIN_PREFIX = $(addprefix $(SRC_DIR), $(SRC_MAIN))

# CC = gcc

# CC_FLAGS = -Wall -Werror -Wextra

# $(OBJ_DIR)%.o : $(SRC_DIR)%.c inc/push_swap.h
# 	@mkdir -p $(OBJ_DIR)
# 	@echo "Compiling:  $<"
# 	@gcc $(CC_FLAGS) -c $< -o $@

# $(NAME): $(OBJECTS_PREFIXED) $(OBJECT_MAIN_PREFIXED)
# 	@make -C $(LIBFT)
# 	@gcc -o $(NAME) $(OBJECTS_PREFIXED) $(OBJ_MAIN_PREFIX) inc/libft/libft.a

# all: $(NAME)

# clean:
# 	@rm -rf $(OBJ_DIR)
# 	@make fclean -C $(LIBFT)

# fclean: clean
# 	@rm -f $(NAME)

# re: fclean all