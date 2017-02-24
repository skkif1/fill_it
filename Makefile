#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/22 18:32:24 by omotyliu          #+#    #+#              #
#    Updated: 2016/12/22 18:32:34 by omotyliu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
SRCS = main.c ft_utility.c map.c file_checker.c algo.c ft_isalpha.c \
ft_putendl.c ft_putstr.c ft_strcat.c ft_strlen.c ft_strnew.c ft_strsplit.c \
ft_strstr.c ft_memalloc.c ft_putchar.c ft_strcpy.c ft_memset.c ft_strncpy.c
HEADERS = fillit.h
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	gcc -Wall -Wextra -Werror -o $@ $?

$(OBJS): $(HEADERS)

.c.o: $(SRCS)
	gcc -Wall -Wextra -Werror -I ./ -c $<

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
