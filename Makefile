# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrami <mrami@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 17:44:38 by mrami             #+#    #+#              #
#    Updated: 2023/02/06 18:03:54 by mrami            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc = cc
HEADER = minitalk.h
CFlags = -Wall -Wextra -Werror
# -------------------------
SERVER = server
CLIENT = client
# -----------------------
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
# ------------------------
S_CFiles = server.c ft_helper.c
S_OFiles = $(S_CFiles:.c=.o)
C_CFiles = client.c ft_helper.c
C_OFiles = $(C_CFiles:.c=.o)
# --------------------------
SB_CFiles = server_bonus.c ft_helper.c
SB_OFiles = $(SB_CFiles:.c=.o)
CB_CFiles = client_bonus.c ft_helper.c
CB_OFiles = $(CB_CFiles:.c=.o)
# ----------------------------

all: $(SERVER) $(CLIENT)
	@echo "Making Successful."

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "Bonus Making Successful."
# ---------------------------------
$(SERVER): $(S_OFiles)
		@$(cc) $(S_CFiles) -o $(SERVER)

$(CLIENT): $(C_OFiles)
		@$(cc) $(C_CFiles) -o $(CLIENT)
# -----------------------------------
$(SERVER_BONUS): $(SB_OFiles)
		@$(cc) $(SB_CFiles) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(CB_OFiles)
		@$(cc) $(CB_CFiles) -o $(CLIENT_BONUS)
# -----------------------------------
%.o : %.c $(HEADER)
	@$(CC) -c $<

clean:
		@rm -f $(S_OFiles) $(C_OFiles) $(SB_OFiles) $(CB_OFiles)
		@echo "Cleaning Successful."

fclean: clean
		@rm -rf $(SERVER) $(CLIENT) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY: all bonus fclean clean re