NAME = pipex
NAME_BONUS = pipex_bonus

HEADER = -I ./headers

CC = gcc
CFLAGES = -Wall -Wextra -Werror

LIBFT = ./include/libft
LIBFT_NAME = libft.a

RM = rm
RMFLAGS = -f

SRCS = ./include/get_next_line/get_next_line.c \

SRCS_BONUS = ./include/get_next_line/get_next_line.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make all -C $(LIBFT)
	@cp $(LIBFT)/$(LIBFT_NAME) $(LIBFT_NAME)
	$(CC) $(CFLAGES) -L. -lft $(LFLAGES) $(LIBS) -o $@ $^

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	@make all -C $(LIBFT)
	@cp $(LIBFT)/$(LIBFT_NAME) $(LIBFT_NAME)
	$(CC) $(CFLAGES)  -L. -lft $(LFLAGES) $(LIBS) -o $@ $^

%.o:%.c
	@$(CC) $(CFLAGES) $(HEADER) -o $@ -c $<	

clean :
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)
	 make clean -C $(LIBFT)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT)

re : fclean all

.PHONY : all fclean clean re
