# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 10:54:09 by abuet             #+#    #+#              #
#    Updated: 2026/04/15 20:58:34 by antoinebuet      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## ARGUMENTS

NAME	= printf
CFLAGS	= -Wall -Wextra -Werror -g
cc 	= cc

################################################################################
## SOURCES

HEADER = ft_printf.h

OPTION = -c -I $(HEADER)

SRC_FILES = ft_printf.c print_string.c ft_deci.c ft_hexa.c ft_ptr.c ft_unsigndeci.c\

OBJ_FILES =  $(SRC_FILES:.c=.o)

################################################################################
## RULES

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(OPTION) $(SRC_FILES)
	@ar rc $(NAME) $(OBJ_FILES)
	

clean: 
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

launch : all 
	@$(CC) $(NAME)
	@./a.out
	@make fclean
.PHONY: all clean fclean launch re