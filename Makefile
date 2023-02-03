# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 18:17:45 by kilchenk          #+#    #+#              #
#    Updated: 2023/02/03 14:27:39 by kilchenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	push_swap.c					\
		swap.c						\
	
SRC_MAIN = main.c

NAME = push_swap

LIBFT = inc/libft/

PRINTF = inc/ft_printf/

OBJ_DIR = obj/
SRC_DIR = src/push_swap/

OBJ = $(SRC:.c=.o)
OBJ_MAIN = $(SRC_MAIN:.c=.o)
OBJ_PREFIX = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ_MAIN_PREFIX = $(addprefix $(OBJ_DIR), $(OBJ_MAIN))
SRC_PREFIX = $(addprefix $(SRC_DIR), $(SRC))
SRC_MAIN_PREFIX = $(addprefix $(SRC_DIR), $(SRC_MAIN))

CC = gcc

CC_FLAGS = -Wall -Werror -Wextra

$(OBJ_DIR)%.o : $(SRC_DIR)%.c inc/push_swap.h
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling:  $<"
	@gcc $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED) $(OBJECT_MAIN_PREFIXED)
	@make -C $(LIBFT)
	@make -C $(PRINTF)
	@gcc -o $(NAME) $(OBJECTS_PREFIXED) $(OBJ_MAIN_PREFIX) inc/libft/libft.a inc/ft_printf/ft_printf.a

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT)
	@make fclean -C $(PRINTF)

fclean: clean
	@rm -f $(NAME)

re: fclean all
