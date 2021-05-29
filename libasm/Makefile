NAME = libasm.a

NASM = nasm
NFLAGES = -f macho64

AR = ar
ARFLAGS = rcs

CC = gcc
CFLAGES = -Wall -Wextra -Werror

RM = rm
RMFLAGS = -f

SRCS = ./ft_strlen.s \
	   ./ft_strcpy.s \
	   ./ft_strcmp.s \
	   ./ft_write.s \
	   ./ft_read.s \
	   ./ft_strdup.s

OBJS = $(SRCS:.s=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

test: $(NAME)
	@$(CC) $(CFLAGS) -o main.c $@ -c $<	

clean :
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME) test

re : fclean all

.PHONY : all fclean clean re test
