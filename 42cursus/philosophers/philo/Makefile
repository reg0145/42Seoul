# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 17:44:07 by donghyuk          #+#    #+#              #
#    Updated: 2022/09/08 03:19:08 by donghyuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	philo.c \
		util.c \
		init.c \
		check.c \
		util_ext.c

CC = cc
CFLAG = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
NAME = philo
BONUS = philo_bonus


all : $(NAME)
bonus : $(BONUS)

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
