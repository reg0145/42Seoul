# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 17:44:07 by donghyuk          #+#    #+#              #
#    Updated: 2022/07/31 02:16:13 by donghyuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		error.c \
		parse.c \
		stack.c
CC = cc
CFLAG = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	$(CC) $(CFLAG) -L./Libft -lft -o $@ $^

%.o : %.c
	$(CC) $(CFLAG) -I./Libft -c -o $@ $<

clean :
	rm -f $(OBJS)
	@make -C libft clean

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)
	@make -C libft fclean

re : fclean all

.PHONY: clean fclean re all
