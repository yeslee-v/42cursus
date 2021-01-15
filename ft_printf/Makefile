NAME = libftprintf.a
HEADER = ft_printf.h

LIBFT = libft
LIBFT_NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rc

RM = rm
RMFLAGS = -f

SRCS = ft_printf.c ft_parsing.c ft_check_flag.c ft_check_width.c \
	   ft_check_prec.c ft_print_d_i.c 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_NAME) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $^

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(RMFLAGS) $(OBJS)
	make clean -C $(LIBFT)

fclean :
	$(RM) $(RMFLAGS) $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY: all fclean clean re
