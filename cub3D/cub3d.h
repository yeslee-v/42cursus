/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:29:08 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/23 12:50:58 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/get_next_line/get_next_line.h"
#include "./include/libft/libft.h"
#include "mlx/mlx.h"
#include <errno.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

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
	char		player;

	char		**map;

	int			cnt_exist;
}				t_map;

typedef struct	s_save
{
	int			pic;
}				t_save;

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_info
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;

	double	oldDirX;
	double	oldPlaneX;
	
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	
	int		mapX;
	int		mapY;

	double	sideDistX;
	double	sideDistY;

	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;

	int		stepX;
	int		stepY;

	int		hit;
	int		side;

	void	*mlx;
	void	*win;

	t_img	img;

	int		**buf;
//	int		texture[8][texHeight * texWidth];

	double	moveSpeed;
	double	rotSpeed;
}				t_info;

typedef struct	s_all
{
	t_game			game;
	t_map			map;
	t_save			save;
	t_info			info;
}				t_all;

int				main(int ac, char **av);
void			mlx_start(t_all *all);

void			ft_init_start(int ac, char **av, t_all *all);
void			ft_t_game_init(t_game *game);
void			ft_t_window_init(t_window *window);
void			ft_t_map_init(t_map *map);
void			ft_t_save_init_on(int ac, char **avi, t_save *save);
void			ft_t_info_init(t_info *info);

int				ft_check_error(int ac, char **av);
void			ft_error_message(int i);

void			ft_read_line(char *line, t_all *all);

void			ft_put_size(char *width, char *height, t_game *game);
void			ft_put_image(char *img, t_game *game);
void			ft_put_color(char *color, int *color_arr, t_game *game);

void			ft_read_map(char *line, t_all *all);
void			ft_input_map(char *line, t_all *all, int len);

void			ft_map_validation(t_all *all);
void			ft_dfs(t_all *all, int **dfs_map, int i, int j);

void			ft_free_all(char **map);
void			ft_free_all_int(t_all *all, int **map);

int				ft_isspace(char c);
int				ft_double_strlen(char **s);

//int				main_loop(t_all *all);
//void			calc(t_all *all);
//int				key_press(int key, t_all *all);
//void			verLine(t_all *all, int x, int y1, int y2, int color);
