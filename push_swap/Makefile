NAME_C = checker
NAME_P = push_swap

HEADER = -I ./headers

CC = gcc
CFLAGES = -Wall -Wextra -Werror

LIBFT = ./include/libft
LIBFT_NAME = libft.a

RM = rm
RMFLAGS = -f

SRCS_C = ./include/get_next_line/get_next_line.c \
		 ./include/get_next_line/get_next_line_utils.c \
		 ./srcs/checker_main.c \
		 ./srcs/write_result.c \
		 ./srcs/struct_init.c \
		 ./srcs/check_ac_av.c \
		 ./srcs/checker.c \
		 ./srcs/actions.c \
		 ./srcs/pivot.c \
		 ./srcs/push_swap.c \
		 ./srcs/optimize.c \
		 ./srcs/optimize_2.c

SRCS_P = ./include/get_next_line/get_next_line.c \
		 ./include/get_next_line/get_next_line_utils.c \
		 ./srcs/push_main.c \
		 ./srcs/write_result.c \
		 ./srcs/struct_init.c \
		 ./srcs/check_ac_av.c \
		 ./srcs/checker.c \
		 ./srcs/actions.c \
		 ./srcs/pivot.c \
		 ./srcs/push_swap.c \
		 ./srcs/optimize.c \
		 ./srcs/optimize_2.c

OBJS_C = $(SRCS_C:.c=.o)
OBJS_P = $(SRCS_P:.c=.o)

all : $(NAME_C) $(NAME_P)

$(NAME_C) : $(OBJS_C)
	@make all -C $(LIBFT)
	@cp $(LIBFT)/$(LIBFT_NAME) $(LIBFT_NAME)
	$(CC) $(CFLAGES) -L. -lft $(LFLAGES) $(LIBS) -o $@ $^

$(NAME_P) : $(OBJS_P)
	@make all -C $(LIBFT)
	@cp $(LIBFT)/$(LIBFT_NAME) $(LIBFT_NAME)
	$(CC) $(CFLAGES)  -L. -lft $(LFLAGES) $(LIBS) -o $@ $^

%.o:%.c
	@$(CC) $(CFLAGES) $(HEADER) -o $@ -c $<	

clean :
	$(RM) $(RMFLAGS) $(OBJS_C) $(OBJS_P)
	$(RM) $(RMFLAGS) $(LIBFT_NAME)
	 make clean -C $(LIBFT)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME_C) $(NAME_P)
	@make fclean -C $(LIBFT)

re : fclean all

.PHONY : all fclean clean re
