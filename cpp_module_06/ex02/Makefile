NAME = identify

HEADER = Base.hpp \
		A.hpp \
		B.hpp \
		C.hpp \
		Identify.hpp

CC = clang++
CFLAGES = -std=c++98 -Wall -Wextra -Werror

RM = rm
RMFLAGS = -f

SRC = main.cpp \
	Base.cpp \
	A.cpp \
	B.cpp \
	C.cpp \
	Identify.cpp

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
