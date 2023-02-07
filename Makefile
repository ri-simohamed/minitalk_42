# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrami <mrami@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 17:44:38 by mrami             #+#    #+#              #
#    Updated: 2023/02/06 19:24:24 by mrami            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc = cc
SERVER = server
CLIENT = client
CFlags = -Wall -Wextra -Werror
# --------------------------------
HEADER = minitalk.h
S_CFiles = server.c ft_helper.c
S_OFiles = $(S_CFiles:.c=.o)
C_CFiles = client.c ft_helper.c
C_OFiles = $(C_CFiles:.c=.o)
# --------------------------------
all: $(SERVER) $(CLIENT)
	@echo "Making Successful."
# --------------------------------
$(SERVER): $(S_OFiles)
		@$(cc) $(S_CFiles) -o $(SERVER)
# --------------------------------
$(CLIENT): $(C_OFiles)
		@$(cc) $(C_CFiles) -o $(CLIENT)
# --------------------------------
%.o : %.c $(HEADER)
	@$(CC) -c $<
# --------------------------------
clean:
		@rm -f $(S_OFiles) $(C_OFiles)
		@echo "Cleaning Successful."
# --------------------------------
fclean: clean
		@rm -rf $(SERVER) $(CLIENT)
# --------------------------------
re: fclean all

.PHONY: all fclean clean re