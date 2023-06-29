CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -L./includes

SRCS     = $(wildcard ./srcs/*.cpp)
OBJS     = $(SRCS:.cpp=.o)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(TARGET)

re : fclean all

.PHONY : all clean fclean re