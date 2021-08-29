NAME = philo

HEADER = -I ./include

CC = gcc
CFLAGES = -Wall -Wextra -Werror
FFLAGES = -g3 -fsanitize=address
PFLAGES = -pthread

RM = rm
RMFLAGS = -f

SRCS = srcs/main.c \
	   srcs/init.c \
	   srcs/utils.c \
	   srcs/do.c \
	   srcs/print.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGES) $(PFLAGES) $(FFLAGES) -o $@ $^
#	@$(CC) $(CFLAGES) $(PFLAGES) -o $@ $^

%.o:%.c
	@$(CC) $(CFLAGES) $(HEADER) -o $@ -c $<

clean :
	@$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all fclean clean re
