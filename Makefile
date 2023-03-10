# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 18:17:45 by kilchenk          #+#    #+#              #
#    Updated: 2023/03/10 19:04:47 by kilchenk         ###   ########.fr        #
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
		src/push_swap/main.c						\
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
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_F)/$(LIB) -o $(NAME)
# @echo "\033[92m.\033[0m\c"

$(LIB_F)/$(LIB):
	@make -C $(LIB_F)
	@echo "\n\033[92mPush_swap successfully compiled!\033[0m"
	@bash minion.sh

clean:
	@$(RM) $(OBJS)
	@rm -rf obj 
	@echo "\033[0;31mPush_swap successfully cleaned!\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB_F)

re: fclean all

		
# SRC =	push_swap.c push_swap_utils.c input_check.c\
# 		parsing.c stacks.c push_op.c swap_op.c rotate_op.c\
# 		rev_rot_op.c utils.c sorts.c

# SRC_MAIN = 	main.c

# SRCS_BONUS = 	checker.c

# NAME = push_swap
# BONUS = checker

# LIBFT = inc/libft/

# OBJS_DIR = objs/
# OBJS_BONUS_DIR = objs_bonus/
# SRCS_DIR = src/push_swap/
# SRCS_BONUS_DIR = src/checker/

# OBJS = $(SRCS:.c=.o)
# OBJ_MAIN = $(SRC_MAIN:.c=.o)
# OBJS_BONUS = $(SRCS_BONUS:.c=.o)
# OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
# OBJECT_MAIN_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJ_MAIN))
# OBJECTS_BONUS_PREFIXED = $(addprefix $(OBJS_BONUS_DIR), $(OBJS_BONUS))
# SOURCES_PREFIXED = $(addprefix $(SRCS_DIR), $(SRCS))
# SOURCE_MAIN_PREFIXED = $(addprefix $(SRCS_DIR), $(SRC_MAIN))
# SOURCES_BONUS_PREFIXED = $(addprefix $(SRCS_BONUS_DIR), $(SRCS_BONUS))

# CC = gcc

# CC_FLAGS = -Wall -Wextra -Werror

# $(OBJS_DIR)%.o : $(SRCS_DIR)%.c inc/push_swap.h
# 	@mkdir -p $(OBJS_DIR)
# 	@echo "Compiling: $<"
# 	@gcc $(CC_FLAGS) -c $< -o $@

# $(OBJS_BONUS_DIR)%.o : $(SRCS_BONUS_DIR)%.c inc/push_swap.h
# 	@mkdir -p $(OBJS_BONUS_DIR)
# 	@echo "Compiling: $<"
# 	@gcc $(CC_FLAGS) -c $< -o $@

# $(NAME): $(OBJECTS_PREFIXED) $(OBJECT_MAIN_PREFIXED)
# 	@make -C $(LIBFT)
# 	@gcc -o $(NAME) $(OBJECTS_PREFIXED) $(OBJECT_MAIN_PREFIXED) inc/libft/libft.a

# $(BONUS): $(OBJECTS_BONUS_PREFIXED) $(OBJECTS_PREFIXED)
# 	@make -C $(LIBFT)
# 	@gcc -o $(BONUS) $(OBJECTS_BONUS_PREFIXED) $(OBJECTS_PREFIXED) inc/libft/libft.a

# bonus: $(BONUS)

# all: $(NAME) $(BONUS)

# clean:
# 	@rm -rf $(OBJS_DIR)
# 	@rm -rf $(OBJS_BONUS_DIR)
# 	@make fclean -C $(LIBFT)


# fclean: clean
# 	@rm -f $(NAME)
# 	@rm -f $(BONUS)

# re: fclean all