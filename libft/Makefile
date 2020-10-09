CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rc

NAME = libft.a
HEADER = ./libft.h

SRC = *.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $(SRC)

$(NAME) : $(OBJ) $(HEADER)
	$(AR) $(ARFLAGS) $@ $^

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
