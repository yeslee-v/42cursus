CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rc

RM = rm -f

NAME = libft.a
HEADER = ./libft.h

SRC = *.c
SRC_BONUS = *.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

.c.o : $(SRC) $(SRC_BONUS)
	$(CC) $(CFLAGS) -c -o $@ $<

bonus : $(OBJ_BONUS)
	$(AR) $(ARFLAGS) $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(AR) $(ARFLAGS) $@ $^

clean :
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
