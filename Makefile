# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snikitin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 20:40:56 by snikitin          #+#    #+#              #
#    Updated: 2018/04/09 12:26:44 by snikitin         ###   ########.fr        #
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
       get_arg_keys.c\
       get_arg_files.c\
	   list_dirs.c\
	   list_files.c\
	   print_usage.c\
	   free.c\
	   sort_files.c\
	   list_to_arr.c\
	   print_files_long.c\
	   get_from_dir.c\
	   del_list.c\
	   reverse.c\
	   swap.c\
	   is.c\
	   get_space_num.c\
	   print.c\
	   print_2.c\
	   get_full_paths.c\
	   get_digit_num.c\
	   puterror.c\
	   ft_itoa_base.c


# project object files

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
INC = $(addprefix $(INC_DIR), $(NAME:=.h))


# libraries

LIBFT =         $(LIBFT_DIR)libft.a
LIBFT_DIR :=    $(LIB_DIR)libft
LIBFT_INC :=    $(LIBFT_DIR)/
LIBFT_FLAGS :=  -lft -L $(LIBFT_DIR)


# compilation flags

CC_FLAGS := -Wall -Wextra -Werror -O3


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

$(OBJ_DIR)%.o: %.c $(INC)
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
