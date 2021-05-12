NAME = libasm.a

NASM = nasm
NFLAGES = -f macho64

CC = gcc
CFLAGES = -Wall -Wextra -Werror

RM = rm
RMFLAGS = -f

SRCS = ./ft_strlen.s \
	   ./ft_strcpy.s \
	   ./ft_strcmp.s \
	   ./ft_write.s \
	   ./ft_read.s \
	   ./ft_strdup.s \
	   ./main.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGES) -o $@ $^

%.o:%.c
	@$(NASM) $(NFLAGES) -o $@ -c $<	

clean :
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all fclean clean re
