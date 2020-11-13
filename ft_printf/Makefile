CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rc

RM = rm -f

NAME = libftprintf.a
HEADER = ./ft_printf.h

SRC = ft_printf.c ./libft/*.c

SRC_BONUS = 

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(AR) $(ARFLAGS) $@ $^

bonus : $(OBJ) $(OBJ_BONUS) $(HEADER)
	$(AR) $(ARFLAGS) $(NAME) $^

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $^
	
$(OBJ_BONUS) : $(SRC_BONUS)
	$(CC) $(CFLAGS) -c $^

clean :
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re