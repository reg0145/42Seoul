NAME     = phonebook
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES_DIR = -L./includes

SRCS = $(wildcard ./srcs/*.cpp)
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES_DIR) -o $(NAME) $(OBJS)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re all bonus