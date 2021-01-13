NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rc

RM = rm -rf

SRC_NAME = ft_printf.c ft_print_d.c ft_parsing.c
SRC_PATH = ./srcs
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

INC_LINK = -I./includes

LIBFT = -L./libft -lft

all : $(NAME)

$(NAME) : $(OBJ) libft
	$(CC) $(CFLAGS) $(OBJ) $(INC_LINK) $(LIBFT) -o $(NAME)
	# $(AR) $(ARFLAGS) $@ $^

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(INC_LINK) -o $@ -c $<

libft:
	@$(MAKE) -C ./libft all

clean:
	@$(MAKE) -C ./libft clean
	$(RM) $(OBJ_PATH)

fclean :
	@$(MAKE) -C ./libft fclean
	$(RM) $(OBJ_PATH) $(NAME)

re : fclean all

.PHONY: all fclean clean re
