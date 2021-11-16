CC = gcc
CFLAG = -Wall -Wextra -Werror
INCLUDE = ./includes/
SRCS = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
TARGET = libft.a

all : $(TARGET)

%.o : %.c
	$(CC) $(CFLAG) -c -I$(INCLUDE) -o $@ $<

$(TARGET) : $(OBJS)
	ar -rcs $@ $^ㄴ

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all
.PHONY:		clean fclean re all