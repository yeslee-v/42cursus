CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rc

RM = rm -f

NAME = libftprintf.a
HEADER = ./ft_printf.h

SRC = ft_printf.c \
    ft_atoi.c \
    ft_print_d.c \
    ft_itoa.c \
    ft_parsing.c \
	ft_len.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $^
	
clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all fclean clean re
