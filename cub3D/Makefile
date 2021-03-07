# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/07 14:38:08 by yeslee            #+#    #+#              #
#    Updated: 2021/03/07 18:18:37 by yeslee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -L ./mlx -lmlx -framework OpenGL -framework AppKit cub3D.h init.c main.c include/libft/ft_strlen.c include/libft/ft_strnstr.c exception_handling.c map_parsing.c include/get_next_line/get_next_line.c include/get_next_line/get_next_line_utils.c include/get_next_line/get_next_line.h include/libft/ft_strncmp.c include/libft/ft_split.c include/libft/ft_strchr.c
	./a.out map.cub --save
