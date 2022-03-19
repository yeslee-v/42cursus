NAME = ft_container

HEADER = Vector.hpp Map.hpp Stack.hpp

CC = clang++
CFLAGES = -std=c++98 -Wall -Wextra -Werror

RM = rm
RMFLAGS = -f

SRC = main.cpp Vector.cpp Map.cpp Stack.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGES) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGES) $(HEADER) -o $@ -c $<

clean :
	$(RM) $(RMFLAGS) $(OBJ)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all fclean clean re
