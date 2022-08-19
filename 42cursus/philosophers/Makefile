# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 17:44:07 by donghyuk          #+#    #+#              #
#    Updated: 2022/08/19 13:18:24 by donghyuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =				main.c \
					util.c \
					check.c

CC = cc
CFLAG = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
NAME = main

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) -o $@ $^

%.o : %.c
	$(CC) $(CFLAG) -c -o $@ $<

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re all
