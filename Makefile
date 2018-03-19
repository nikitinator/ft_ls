# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snikitin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 20:40:56 by snikitin          #+#    #+#              #
#    Updated: 2018/03/18 17:47:21 by snikitin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name of the executable file

NAME := ft_ls 

# project directories

SRC_DIR := ./src/
OBJ_DIR := ./obj/
INC_DIR := ./inc/
LIB_DIR := ./lib/

# project source files

SRC := main.c\
	   print_usage.c\
       get_params.c

# project object files

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
INC = $(addprefix $(INC_DIR), $(NAME:=.h))

# libraries

LIBFT =         $(LIBFT_DIR)libft.a
LIBFT_DIR :=    $(LIB_DIR)libft
LIBFT_INC :=    $(LIBFT_DIR)/
LIBFT_FLAGS :=  -lft -L $(LIBFT_DIR)


# compilation flags

CC_FLAGS := -Wall -Wextra -Werror


# linking flags

LINK_FLAGS := $(LIBFT_FLAGS)


# header flags

HEADER_FLAGS := -I $(INC_DIR) -I $(LIBFT_INC)

# compiler

CC := gcc


# rules

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
#$(INC)
$(OBJ_DIR)%.o: %.c 
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all


# special stuff

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
