# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrami <mrami@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 17:33:59 by mrami             #+#    #+#              #
#    Updated: 2023/02/04 21:27:35 by mrami            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

server: server.o libft
	@$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	@$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	@$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

clean:
	rm -f $(OBJECTS)
	@make -C libft clean
	
fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re
