# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 17:44:07 by donghyuk          #+#    #+#              #
#    Updated: 2022/09/06 01:29:10 by donghyuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	philo.c \
		util.c \
		init.c \
		check.c \
		util_ext.c

BONUS_SRC = philo_bonus.c \
			util_ext_bonus.c \
			util_bonus.c

CC = cc
SRC_DIR = ./src/
SRCS = $(addprefix $(SRC_DIR), $(SRC))
CFLAG = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
BONUS_OBJS= $(BONUS_SRC:.c=.o)
NAME = philo
BONUS = philo_bonus


all : $(NAME)
bonus : $(BONUS)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) -I ./includes/ -o $@ $^

$(BONUS) : $(BONUS_OBJS)
	$(CC) -fsanitize=thread $(CFLAG) -o $@ $^

%.o : %.c
	$(CC) $(CFLAG) -I ./includes/ -c -o $@ $<

clean :
	rm -f $(BONUS_OBJS)
	rm -f $(OBJS)

fclean :
	rm -f $(BONUS_OBJS)
	rm -f $(BONUS)
	rm -f $(OBJS)
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re all
