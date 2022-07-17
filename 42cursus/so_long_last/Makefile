# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyuk <donghyuk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 17:44:07 by donghyuk          #+#    #+#              #
#    Updated: 2022/07/18 03:34:58 by donghyuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =				main.c \
					util.c \
					event.c \
					check_map.c \
					check_object.c \
					draw.c \
					ft_split.c \
					ft_strjoin.c \
					game.c \
					image.c \
					map.c \
					object.c \
					util.c

CC = cc
CFLAG = -Wall -Wextra -Werror
FRAMEWORK = -framework OpenGL -framework AppKit
OBJS = $(SRCS:.c=.o)
NAME = so_long

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C mlx
	$(CC) $(CFLAG) $(FRAMEWORK) -L./mlx -lmlx -o $@ $^

%.o : %.c
	$(CC) $(CFLAG) -c -o $@ $<

clean :
	rm -f $(OBJS)
	@make -C mlx clean

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)
	@make -C mlx fclean

re : fclean all

.PHONY: clean fclean re all
