NAME = phonebook
HEADER = phonebook.hpp

CC = clang++
#-STD = c++98
CFLAGES = -Wall -Wextra -Werror 

RM = rm
RMFLAGS = -f

SRC = main.cpp \
		phonebook.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(-STD) $(CFLAGES) -o $@ $^

%.o:%.c
	$(CC) $(-STD) $(CFLAGES) $(HEADER) -o $@ -c $<

clean :
	$(RM) $(RMFLAGS) $(OBJ)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all fclean clean re
