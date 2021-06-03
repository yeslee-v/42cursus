NAME = libasm.a

NASM = nasm
NFLAGS = -f macho64

AR = ar
ARFLAGS = rcs

CC = gcc
CFLAGES = -Wall -Wextra -Werror -l -Lasm

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
	@$(CC) $(CFLAGS) $^ main.c -o test
	@./test

clean :
	@$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME) test

re : fclean all

%.o : %.s
	@$(NASM) $(NFLAGS) $< -o $@

.PHONY : all fclean clean re test
