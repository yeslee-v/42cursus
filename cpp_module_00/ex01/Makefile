NAME = phonebook

HEADER = contact.hpp \
		phonebook.hpp

CC = clang++ -std=c++98
CFLAGES = -Wall -Wextra -Werror 

RM = rm
RMFLAGS = -f

SRC = main.cpp \
	contact.cpp \
	phonebook.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGES) -o $@ $^

%.o:%.c
	@$(CC) $(CFLAGES) $(HEADER) -o $@ -c $<

clean :
	@$(RM) $(RMFLAGS) $(OBJ)

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all fclean clean re
