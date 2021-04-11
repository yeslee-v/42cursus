/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:29:08 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/11 01:06:51 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../headers/get_next_line.h"
# include "../headers/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

# define KEY_ESC		53

# define KEY_ARROW_L	123		
# define KEY_ARROW_R	124		
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define IMG_DEPTH		3

# define FILE_HEADER_SIZE	14
# define INFO_HEADER_SIZE	40

# define BMP_BPP 24

typedef struct	s_scr
{
	int			c_sizeX;
	int			c_sizeY;
}				t_scr;

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

	int			num_sp;
	
	double		player_row;
	double		player_col;
	
	char		player;
	char		**map;

	int			cnt_exist;
}				t_map;

typedef struct	s_save
{
	int			pic;

	unsigned char	file_header[14];
	unsigned char	info_header[40];
}				t_save;

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		bpp;
	int		size_l;
	int		endian;

	char	*path;

	int		img_width;
	int		img_height;
}				t_img;

typedef struct	s_info
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	double	camera_x;
	double	ray_x;
	double	ray_y;
	
	int		map_x;
	int		map_y;

	double	side_x;
	double	side_y;

	double	delta_x;
	double	delta_y;
	double	perp;

	double	step;
	int		step_x;
	int		step_y;

	int		hit;
	int		side;

	int		line_h;
	int		draw_s;
	int		draw_e;
	int		tex_n;

	int		tex_x;
	int		tex_y;
	int		color;

	double	wall_x;
	double	tex_pos;

	void	*mlx;
	void	*win;

	int		**buf;
	int		**tex;

	double	move_s;
	double	rot_s;

	int		tex_w;
	int		tex_h;
}				t_info;

typedef struct	s_sprite
{
	double	x;
	double	y;
}				t_sprite;

typedef struct	s_sp_buf
{
	int		*sp_order;

	double	*sp_dist;
	double	*z_buf;

	double	sp_x;
	double	sp_y;

	double	inv_det;

	double	tran_x;
	double	tran_y;

	int		sp_scx;
	
	int		sp_w;
	int		sp_h;

	int		start_dx;
	int		start_dy;
	
	int		end_dx;
	int		end_dy;

	int		stripe;

	int		tex_x;
	int		tex_y;

	int		dy;
	
	t_sprite	*sprite;
}				t_sp_buf;

typedef struct	s_all
{
	t_scr			scr;
	t_img			img;
	t_game			game;
	t_map			map;
	t_save			save;
	t_info			info;
	t_sp_buf		sp;
}				t_all;

int				main(int ac, char **av);
void			ft_map_parsing_intro(int ac, char **av, t_all *all);
int				ft_mlx_intro(t_all *all);

void			ft_init_start(int ac, char **av, t_all *all);
void			ft_struct_init(int ac, char **av, t_all *all);

int				ft_check_error(int ac, char **av);
void			ft_error_message(int i);

void			ft_read_line(char *line, t_all *all);

void			ft_put_size(char *width, char *height, t_game *game);
void			ft_put_image(char *img, char **txtr_addr, t_game *game);
void			ft_put_color(char *line, t_game *game);

void			ft_read_map(char *line, t_all *all);
void			ft_input_map(char *line, t_all *all, int len);

void			ft_map_validation_intro(t_all *all);
void			ft_dfs(t_all *all, int **dfs_map, int i, int j);

void			ft_free_all(char **map, int max);
void			ft_free_all_int(int **map, int max);

int				ft_isspace(char c);
int				ft_double_strlen(char **s);

void			ft_t_info_init(t_all *all);
void			ft_nesw_intro(t_all *all, int i, int j);
void			ft_nesw_init(t_all *all, int i, int j);
void			ft_calc_save_init(t_all *all, int x);

int				ft_set_texnum(t_all *all);

void			ft_put_step_side_value(t_all *all);
void			ft_dda(t_all *all);
void			ft_draw_wall(t_all *all);
void			ft_paint_texture(t_all *all, int x);

int				ft_press_key(int key, t_all *all);
int				ft_close();

void			ft_bgm_start(void);
void			ft_bgm_end(void);

void			ft_set_screen_size(t_all *all);
int				ft_main_loop(t_all *all);

void			ft_allocate_texture(t_all *all);
void			ft_allocate_buf(t_all *all);
void			ft_allocate_buf_for_sprite(t_all *all);

void			load_texture(t_all *all);
void			ft_load_image(t_info *info, int *texture, char *path,
				t_img *img);

void			ft_img_draw(t_all *all);
void			ft_paint_f_c(t_all *all);

int				ft_save_bmp_intro(t_all *all);

int				ft_sprite_loop(t_all *all);
void			ft_sort_sprite_init(t_all *all);
void			ft_sort_sprite(int *buf1, double *buf2, int num);

void			ft_clean_buffer(t_all *all);
void			ft_paint_sprite(t_all *all);

void			ft_bubble_sort(int *buf1, double *buf2, int num);

void	ft_free_char(char **map);

#endif
