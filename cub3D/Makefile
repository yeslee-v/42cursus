NAME = cub3D
NAME_BONUS = cub3D_bonus

HEADER = -I ./headers

CC = gcc
CFLAGES = -Wall -Wextra -Werror

LIBFT = ./include/libft
LIBFT_NAME = libft.a

LFLAGES = -L./mlx
LIBS = -lmlx -framework AppKit

MLX = ./mlx
MLX_NAME = libmlx.dylib

RM = rm
RMFLAGS = -f

SRCS = ./include/get_next_line/get_next_line.c \
	   ./include/get_next_line/get_next_line_utils.c \
	   ./srcs/parse_init.c \
	   ./srcs/exception_handling.c \
	   ./srcs/map_parsing_1.c \
	   ./srcs/put_util.c \
	   ./srcs/put_size_img_color.c \
	   ./srcs/map_parsing_2.c \
	   ./srcs/map_validation.c \
	   ./srcs/mlx_main.c \
	   ./srcs/mlx_init.c \
	   ./srcs/mlx_init_1.c \
	   ./srcs/mlx_init_2.c \
	   ./srcs/mlx_put.c \
	   ./srcs/input_key.c \
	   ./srcs/draw_paint.c \
	   ./srcs/draw_sprite.c \
	   ./srcs/draw_sprite_1.c \
	   ./srcs/bubble_sort.c \
	   ./srcs/save_bmp.c \
	   ./srcs/free.c \
	   ./srcs/main.c

SRCS_BONUS = ./include/get_next_line/get_next_line.c \
			 ./include/get_next_line/get_next_line_utils.c \
			 ./srcs/parse_init.c \
			 ./srcs/exception_handling.c \
			 ./srcs/map_parsing_1.c \
			 ./srcs/put_util.c \
			 ./srcs/put_size_img_color.c \
			 ./srcs/map_parsing_2.c \
			 ./srcs/map_validation.c \
			 ./srcs/mlx_main_bonus.c \
			 ./srcs/mlx_init.c \
			 ./srcs/mlx_init_1.c \
			 ./srcs/mlx_init_2.c \
			 ./srcs/mlx_put.c \
			 ./srcs/input_key_bonus.c \
			 ./srcs/draw_paint.c \
			 ./srcs/draw_sprite.c \
			 ./srcs/draw_sprite_1.c \
			 ./srcs/bubble_sort.c \
			 ./srcs/save_bmp.c \
			 ./srcs/free.c \
			 ./srcs/bgm.c \
			 ./srcs/main.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make all -C $(LIBFT)
	@make all -C $(MLX)
	@cp $(LIBFT)/$(LIBFT_NAME) $(LIBFT_NAME)
	@cp $(MLX)/$(MLX_NAME) $(MLX_NAME)
	$(CC) $(CFLAGES) -L. -lft $(LFLAGES) $(LIBS) -o $@ $^

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	@make all -C $(LIBFT)
	@make all -C $(MLX)
	@cp $(LIBFT)/$(LIBFT_NAME) $(LIBFT_NAME)
	@cp $(MLX)/$(MLX_NAME) $(MLX_NAME)
	$(CC) $(CFLAGES)  -L. -lft $(LFLAGES) $(LIBS) -o $@ $^

%.o:%.c
	@$(CC) $(CFLAGES) $(HEADER) -o $@ -c $<	

clean :
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)
	$(RM) $(RMFLAGS) $(LIBFT_NAME) $(MLX_NAME)
	 make clean -C $(LIBFT)
	 make clean -C $(MLX)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT)
	 make clean -C $(MLX)

re : fclean all

.PHONY : all fclean clean re
