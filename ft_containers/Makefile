NAME = ft_container

CC = clang++
CFLAGES = -std=c++98 -Wall -Wextra -Werror

RM = rm
RMFLAGS = -f

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGES) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGES) -o $@ -c $<

clean :
	$(RM) $(RMFLAGS) $(OBJ)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all fclean clean re
