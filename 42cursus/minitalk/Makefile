# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 17:44:07 by donghyuk          #+#    #+#              #
#    Updated: 2022/05/05 17:44:06 by donghyuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Wextra -Werror

SERVER_SRC = server.c server_util.c common_util.c
CLIENT_SRC = client.c common_util.c

SERVER_BONUS_SRC = server_bonus.c server_util_bonus.c common_util_bonus.c
CLIENT_BONUS_SRC = client_bonus.c common_util_bonus.c

NAME = server client

all : $(NAME)

server : $(SERVER_SRC)
	$(CC) $(CFLAG) -o $@ $^

client : $(CLIENT_SRC)
	$(CC) $(CFLAG) -o $@ $^

bonus : 
	@make SERVER_SRC="$(SERVER_BONUS_SRC)" CLIENT_SRC="$(CLIENT_BONUS_SRC)"
	
clean :
	rm -f $(NAME)
	
fclean : clean

re : fclean all

.PHONY: bonus clean fclean re all
