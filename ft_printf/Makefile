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

SRCS = ft_printf.c ft_parsing.c parse_flag.c parse_wid_prec.c parse_result.c \
	   print_num.c itoa_base.c

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

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY: all fclean clean re
