/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:29:08 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/16 22:02:31 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/get_next_line/get_next_line.h"
#include "./include/libft/libft.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

# define KEY_ESC		53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct	s_window
{
	int			width;
	int			height;
}				t_window;

typedef struct	s_game
{
	t_window		r;

	char			*n;
	char			*s;
	char			*e;
	char			*w;

	char			*sp;

	int			f[3];
	int			c[3];

	int			cnt;
}				t_game;

typedef struct	s_map
{
	int			row;
	int			col;

	int			player_row;
	int			player_col;

	int			**map;

	int			cnt_exist;
}				t_map;

typedef struct	s_save
{
	int			pic;
}				t_save;

typedef struct	s_all
{
	t_game			game;
	t_map			map;
	t_save			save;
}				t_all;

int				main(int ac, char **av);

void			ft_t_game_init(t_game *game);
void			ft_t_window_init(t_window *window);
void			ft_t_map_init(t_map *map);
void			ft_t_save_init_on(int ac, char **avi, t_save *save);

int				ft_check_error(int ac, char **av);
void			ft_error_message(int i);

void			ft_read_line(char *line, t_all *all);

void			ft_put_size(char *width, char *height, t_game *game);
void			ft_put_image(char *img, t_game *game);
void			ft_put_color(char *color, int *color_arr, t_game *game);

void			ft_read_map(char *line, t_all *all);
void			ft_input_map(char *line, t_all *all, int len);

void			ft_map_validation(t_all *all);
int				ft_dfs(t_all *all, int i, int j);

int				ft_isspace(char c);
int				ft_double_strlen(char **s);
