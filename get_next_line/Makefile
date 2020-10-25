CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rc

RM = rm -f

NAME = get_next_line.a
HEADER = ./get_next_line.h

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c -D BUFFER_SIZE=XX $^
	
clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all
	
.PHONY: all clean fclean re
