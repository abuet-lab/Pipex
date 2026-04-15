# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/15 20:29:27 by antoinebuet       #+#    #+#              #
#    Updated: 2026/04/15 20:50:56 by antoinebuet      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## ARGUMENTS

NAME	= pipex
CFLAGS	= -Wall -Wextra -Werror -g 
CC 	= cc
ARGS ?= 
################################################################################
## SOURCES

OPTION = -I. -Ilibft

SRC_FILES = pipex.c

OBJ_FILES =  $(SRC_FILES:.c=.o)

################################################################################
## RULES

all: $(NAME)

$(NAME): libft/libft.a $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) libft/libft.a -o $(NAME)

libft/libft.a:
	@make -C libft
	
%.o: %.c
	@$(CC) $(CFLAGS) $(OPTION) -c $< -o $@
	
clean:
	@rm -f $(OBJ_FILES)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

launch : all 
	@./$(NAME) $(ARGS)
	@make fclean
	
.PHONY: all clean fclean launch re