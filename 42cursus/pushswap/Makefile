# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 17:44:07 by donghyuk          #+#    #+#              #
#    Updated: 2022/08/05 02:22:05 by donghyuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	push_swap.c \
		error.c \
		parse.c \
		algorithm.c \
		algorithm_sub.c \
		algorithm_util.c \
		algorithm_ext.c \
		lis.c \
		lis_util.c \
		util.c \
		command.c \
		command_ext.c

BONUS_SRCS = checker_bonus.c \
		command_bonus.c \
		command_ext_bonus.c \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
		push_swap_bonus.c \
		parse_bonus.c \
		error_bonus.c \
		util_bonus.c

CC = cc
CFLAG = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
BONUS = checker
NAME = push_swap

all : $(NAME)
bonus : $(BONUS)

$(NAME) : $(OBJS)
	@make -C libft
	$(CC) $(CFLAG) -L./Libft -lft -o $@ $^

%.o : %.c
	$(CC) $(CFLAG) -I./Libft -c -o $@ $<

$(BONUS) : $(BONUS_OBJS)
	make -C libft
	$(CC) $(CFLAGS) -L./Libft -lft -o $@ $^

clean :
	rm -f $(OBJS)
	@make -C libft clean

fclean :
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	rm -f $(BONUS)
	rm -f $(NAME)
	@make -C libft fclean

re : fclean all

.PHONY: clean fclean re all
