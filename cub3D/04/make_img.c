#include <stdio.h>
#include "../mlx/mlx.h"

# define WIN_WIDTH	700
# define WIN_HEIGHT	500

# define IMG_WIDTH	400
# define IMG_HEIGHT	300

# define ROWS		11
# define COLS		15

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

int	main(void)
{
	t_mlx	*mlx;
	t_img	img;

	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A simple example");
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	
	draw_box(img, -1, 200, 0x0a80f0);
	draw_box(img, 250, 100, 0x890aff);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img.img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
