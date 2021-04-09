NAME = cub3D
NAME_BONUS = cub3D_bonus

HEADER = -I ./headers

CC = gcc
CFLAGES = -Wall -Wextra -Werror -fsanitize=address -g3

LFLAGES = -L ./mlx
LIBS = -lmlx -framework AppKit

MLX = ./mlx
MLX_NAME = libmlx.dylib

RM = rm
RMFLAGS = -f

SRCS = ./include/get_next_line/get_next_line.c \
	   ./include/get_next_line/get_next_line_utils.c \
	   ./include/libft/ft_strncmp.c \
	   ./include/libft/ft_split.c \
	   ./include/libft/ft_strchr.c \
	   ./include/libft/ft_strlen.c \
	   ./include/libft/ft_strnstr.c \
	   ./include/libft/ft_atoi.c \
	   ./include/libft/ft_isdigit.c \
	   ./include/libft/ft_strdup.c \
	   ./include/libft/ft_size.c \
	   ./include/libft/ft_calloc.c \
	   ./include/libft/ft_memset.c \
	   ./include/libft/ft_bzero.c \
	   ./include/libft/ft_strtrim.c \
	   ./srcs/main.c \
	   ./srcs/parse_init.c \
	   ./srcs/exception_handling.c \
	   ./srcs/map_parsing_1.c \
	   ./srcs/map_parsing_2.c \
	   ./srcs/put_size_img_color.c \
	   ./srcs/map_validation.c \
	   ./srcs/mlx_main.c \
	   ./srcs/mlx_init.c \
	   ./srcs/mlx_init_2.c \
	   ./srcs/mlx_put.c \
	   ./srcs/input_key.c \
	   ./srcs/draw_paint.c \
	   ./srcs/draw_sprite.c \
	   ./srcs/bubble_sort.c \
	   ./srcs/save_bmp.c \
	   ./srcs/free.c \

SRCS_BONUS = ./include/get_next_line/get_next_line.c \
			 ./include/get_next_line/get_next_line_utils.c \
			 ./include/libft/ft_strncmp.c \
			 ./include/libft/ft_split.c \
			 ./include/libft/ft_strchr.c \
			 ./include/libft/ft_strlen.c \
			 ./include/libft/ft_strnstr.c \
			 ./include/libft/ft_atoi.c \
			 ./include/libft/ft_isdigit.c \
			 ./include/libft/ft_strdup.c \
			 ./include/libft/ft_size.c \
			 ./include/libft/ft_calloc.c \
			 ./include/libft/ft_memset.c \
			 ./include/libft/ft_bzero.c \
			 ./include/libft/ft_strtrim.c \
			 ./srcs/main.c \
			 ./srcs/parse_init.c \
			 ./srcs/exception_handling.c \
			 ./srcs/map_parsing_1.c \
			 ./srcs/map_parsing_2.c \
			 ./srcs/put_size_img_color.c \
			 ./srcs/map_validation.c \
			 ./srcs/mlx_main_bonus.c \
			 ./srcs/mlx_init.c \
			 ./srcs/mlx_init_2.c \
			 ./srcs/mlx_put.c \
			 ./srcs/input_key_bonus.c \
			 ./srcs/draw_paint.c \
			 ./srcs/draw_sprite.c \
			 ./srcs/bubble_sort.c \
			 ./srcs/save_bmp.c \
			 ./srcs/free.c \
			 ./srcs/bgm.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make all -C $(MLX)
	@cp $(MLX)/$(MLX_NAME) $(NAME)
	$(CC) $(CFLAGES) $(LFLAGES) $(LIBS) -o $@ $^
	@install_name_tool -change $(MLX_NAME) $(MLX)/$(MLX_NAME) $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	@make all -C $(MLX)
	@cp $(MLX)/$(MLX_NAME) $(NAME_BONUS)
	$(CC) $(CFLAGES) $(LFLAGES) $(LIBS) -o $@ $^
	@install_name_tool -change $(MLX_NAME) $(MLX)/$(MLX_NAME) $(NAME_BONUS)

%.o:%.c
	@$(CC) $(CFLAGES) $(HEADER) -o $@ -c $<

clean :
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all fclean clean re
