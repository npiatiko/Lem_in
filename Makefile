#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/08 10:57:33 by npiatiko          #+#    #+#              #
#    Updated: 2019/02/08 10:57:34 by npiatiko         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in
FLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS = main.c parsing.c links.c aux_fns1.c algorithm.c way.c arrayways.c moveants.c bfs.c aux_fns2.c aux_fns3.c readrooms.c

OBJS = $(SRCS:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(OBJS) -o $(NAME) -L libft/ -lft

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

lib:
	@make -C libft/

clean:
	make -C libft/ clean
	rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all