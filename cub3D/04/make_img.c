#include <stdio.h>
#include "../mlx/mlx.h"

# define WIN_WIDTH	700
# define WIN_HEIGHT	500

# define IMG_WIDTH	200
# define IMG_HEIGHT	300

typedef struct	s_img
{
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

void draw_box(t_img img)
{
	int		count_w;
	int		count_h;

	count_h = 200;
	while (++count_h < IMG_HEIGHT)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
		{
			if (count_w % 2)
				img.data[count_h * IMG_WIDTH + count_w] = 0x890aff;
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
	
	draw_box(img);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img.img_ptr, 0, 0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
