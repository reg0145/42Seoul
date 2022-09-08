# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 17:44:07 by donghyuk          #+#    #+#              #
#    Updated: 2022/09/08 15:18:33 by donghyuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	philo_bonus.c \
		util_bonus.c \
		check_bonus.c \
		init_bonus.c \
		philo_ext_bonus.c \
		util_ext_bonus.c \
		check_ext_bonus.c

CC = cc
CFLAG = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)
NAME = philo_bonus

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
