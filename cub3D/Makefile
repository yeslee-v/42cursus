# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/07 14:38:08 by yeslee            #+#    #+#              #
#    Updated: 2021/03/16 12:05:22 by yeslee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -L ./mlx -lmlx -framework OpenGL -framework AppKit \
		cub3d.h init.c main.c \
		exception_handling.c map_parsing_1.c map_parsing_2.c \
		put_size_img_color.c \
		include/get_next_line/get_next_line.c \
		include/get_next_line/get_next_line_utils.c \
		include/get_next_line/get_next_line.h \
		include/libft/ft_strncmp.c \
		include/libft/ft_split.c \
		include/libft/ft_strchr.c \
		include/libft/ft_strlen.c \
		include/libft/ft_strnstr.c \
		include/libft/ft_atoi.c \
		include/libft/ft_isdigit.c \
		include/libft/ft_strdup.c
	./a.out map.cub
