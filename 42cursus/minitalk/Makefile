# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 17:44:07 by donghyuk          #+#    #+#              #
#    Updated: 2022/05/04 18:25:30 by donghyuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Wextra -Werror
SERVER_SRC = server.c server_util.c common_util.c
CLIENT_SRC = client.c common_util.c

NAME = server
all : $(NAME)

$(NAME) : $(SERVER_SRC)
	$(CC) $(CFLAG) -o $@ $?

$(CLIENT) : $(CLIENT_SRC)
	$(CC) $(CFLAG) -o $@ $?

clean :
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	rm -f $(NAME)

bonus : $(NAME) $(BOBJS)
	ar -rcs $?

re : fclean all

.PHONY: bonus clean fclean re all
