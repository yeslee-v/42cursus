NAME = philo

HEADER = philo.h

CC = gcc
CFLAGES = -Wall -Wextra -Werror
PFLAGE = -lpthread

RM = rm
RMFLAGS = -f

SRCS = ./main.c \
	   ./init.c \
	   ./print.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGES) $(PFLAGE) -o $@ $^

%.o:%.c
	@$(CC) $(CFLAGES) $(HEADER) -o $@ -c $<	

clean :
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all fclean clean re
