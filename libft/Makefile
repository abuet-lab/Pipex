# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoinebuet <antoinebuet@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/07 15:03:41 by abuet             #+#    #+#              #
#    Updated: 2026/05/12 14:51:53 by antoinebuet      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## ARGUMENTS

NAME	= libft.a
CFLAGS	= -Wall -Wextra -Werror
cc 	= cc

################################################################################
## SOURCES

OPTION = -c -I. -Iget_next_line -Ift_printf

SRC_FILES = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_itoa.c \
	ft_split.c \
 	ft_strlcat.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	ft_printf/ft_printf.c \
      ft_printf/ft_deci.c \
      ft_printf/ft_hexa.c \
      ft_printf/ft_ptr.c \
      ft_printf/ft_unsigndeci.c \
      ft_printf/print_string.c

OBJ_FILES =  $(SRC_FILES:.c=.o)

################################################################################
## RULES

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@make -C ft_printf
	@ar rc $(NAME) $(OBJ_FILES)

%.o: %.c
	@$(CC) $(CFLAGS) $(OPTION) -c $< -o $@
	
clean: 
	@rm -f $(OBJ_FILES)
	@rm -f get_next_line/*.o
	@make -C ft_printf clean

fclean: clean
	@rm -f $(NAME)
	@make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
