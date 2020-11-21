CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rc

RM = rm -f

NAME = libft.a
HEADER = libft.h

SRC = *.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $^
	
clean :
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re 
