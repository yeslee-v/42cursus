NAME = DiamondTrap

HEADER = ClapTrap.hpp \
		ScavTrap.hpp \
		FragTrap.hpp \
		DiamondTrap.hpp

CC = clang++
CFLAGES = -std=c++98 -Wshadow -Wall -Wextra -Werror

RM = rm
RMFLAGS = -f

SRC = main.cpp \
	ClapTrap.cpp \
	ScavTrap.cpp \
	FragTrap.cpp \
	DiamondTrap.cpp

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
