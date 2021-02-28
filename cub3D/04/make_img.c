#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../mlx/mlx.h"

# define WIN_WIDTH	700
# define WIN_HEIGHT	500

# define IMG_WIDTH	400
# define IMG_HEIGHT	300

# define ROWS		5
# define COLS		5

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_release	3
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC				53
# define KEY_Q					12
# define KEY_W					13
# define KEY_E					14
# define KEY_R					15
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

typedef struct	s_img
{
	void	*img; // Add at 06

	void	*img_ptr;
	int		*data;
	
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win;
}				t_mlx;

typedef	struct	s_game
{
	t_img	img;

	int		map[ROWS][COLS];
}				t_game;

void draw_box(t_img img, int width, int height, int color)
{
	int		count_w;
	int		count_h;

	count_h = height;
	while (++count_h < IMG_HEIGHT) // 400
	{
		count_w = width;
		while (++count_w < IMG_WIDTH) // 300
		{
			if (count_w)
				img.data[count_h * IMG_WIDTH + count_w] = color;
			else
				img.data[count_h * IMG_WIDTH + count_w] = 0x000000;
		}
	}
}

void wall_to_map(t_game game, t_img img)
{
	int i;
	int j;

	i = 0;
	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
		{
			if (game.map[i][j] == 1)
				draw_box(img, 330, 230, 0x890aff);
			j++;
		}
		i++;	
	}
}

void game_init(t_game *game)
{
	int	map[ROWS][COLS] = {
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1}
	};
	memcpy(game->map, map, sizeof(int) * ROWS * COLS);
}

int	main(void)
{
	t_mlx	*mlx;
	t_img	img;
	t_game	game;

	game_init(&game);
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);

	wall_to_map(game, img);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img.img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
