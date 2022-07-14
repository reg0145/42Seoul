# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 17:44:07 by donghyuk          #+#    #+#              #
#    Updated: 2022/07/09 21:18:35 by donghyuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAG = -Wall -Wextra -Werror

SOLONG_SRC = solong.c util.c

SOLONG_BONUS_SRC = client_bonus.c common_util_bonus.c

NAME = solong

all : $(NAME)

solong : $(SOLONG_SRC)
	$(CC) $(CFLAG) -o $@ $^

bonus :
	@make SOLONG_SRC="$(SOLONG_BONUS_SRC)"

clean :
	rm -f $(NAME)

fclean : clean

re : fclean all

.PHONY: bonus clean fclean re all
