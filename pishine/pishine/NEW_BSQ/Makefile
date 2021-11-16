CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=bsq
SRCS=./srcs/main.c ./srcs/process_map.c ./srcs/util.c ./srcs/set_map.c ./srcs/check_map.c
OBJS=./srcs/main.o ./srcs/process_map.o ./srcs/util.o ./srcs/set_map.o ./srcs/check_map.o
INCS=./include/

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) -I $(INCS) $^

%.o : %.c
	$(CC) $(CFLAGS) -c -I $(INCS) -o $@ $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
