/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textured.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:58:03 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/31 21:59:34 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	ft_img_draw(t_all *all)
{
	int x;
	int y;

	y = 0;
	while (y < all->game.r.height)
	{
		x = 0;
		while (x < all->game.r.width)
		{
            all->img.data[y * all->game.r.width + x] = all->info.buf[y][x];
			x++;
		}
		y++;
	}
    mlx_put_image_to_window(all->info.mlx, all->info.win, all->img.img, 0, 0);
}

void	ft_allocate_buf(t_all *all)
{
	int i;

	i = 0;
	all->info.buf = malloc(sizeof(int *) * all->game.r.height);
	if (!(all->info.buf))
		return ;
	while (i < all->game.r.height)
	{
		all->info.buf[i] = malloc(sizeof(int) * all->game.r.width);
		if (!(all->info.buf[i]))
		{
			ft_free_all_int(all->info.buf, i);
			return ;
		}
		i++;
	}
}

void	ft_paint_f_c(t_all *all)
{
	int x;
	int y;

	x = 0;
	while (x < all->game.r.width)
    {
		y = 0;
        while (y < all->game.r.height)
        {
            all->info.buf[y][x] = ((all->game.c[0] * 256 * 256) +
					(all->game.c[1] * 256) + all->game.c[2]); 
            all->info.buf[all->game.r.height - y - 1][x] =
				((all->game.f[0] * 256 * 256) + (all->game.f[1] * 256)
				 + all->game.f[2]); 
			y++;
        }
		x++;
    }
}

int	ft_set_texnum(t_all *all)
{
	int num;

	num = 3;
	if (all->info.side == 0 && all->info.rayDirX < 0)
		num = 0;
	else if (all->info.side == 0 && all->info.rayDirX > 0)
		num = 1;
	else if (all->info.side == 1 && all->info.rayDirY < 0)
		num = 2;
	//else if (side == 1 && rayY > 0)
	//	num = 3;
	return (num);
}

int	ft_calc_save_map(t_all *all)
{
	int x;
	ft_allocate_buf(all);
	ft_paint_f_c(all);

	x = 0;
    while (x < all->game.r.width)
    {
		ft_calc_save_init(all, x);
        ft_put_step_side_value(all);
		ft_dda(all);
		ft_draw_wall(all);
		ft_paint_texture(all, x);
        x++;
    }
	return (0);
}

int ft_main_loop(t_all *all)
{
	ft_calc_save_map(all);
    ft_img_draw(all);

    return (0);
}

void    ft_load_image(t_info *info, int *texture, char *path, t_img *img)
{
    img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
    img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
    for (int y = 0; y < img->img_height; y++)
    {
        for (int x = 0; x < img->img_width; x++)
        {
            texture[img->img_width * y + x] = img->data[img->img_width * y + x];
        }
    }
    mlx_destroy_image(info->mlx, img->img);
}

void    load_texture(t_all *all)
{
    ft_load_image(&all->info, all->info.texture[0], "pics/wall_n.xpm", &all->img);
    ft_load_image(&all->info, all->info.texture[1], "pics/wall_s.xpm", &all->img);
    ft_load_image(&all->info, all->info.texture[2], "pics/wall_w.xpm", &all->img);
    ft_load_image(&all->info, all->info.texture[3], "pics/wall_e.xpm", &all->img);
}

int ft_mlx_intro(t_all *all)
{
    all->info.mlx = mlx_init();
	ft_set_screen_size(all);
	ft_allocate_texture(all);
    load_texture(all);

	all->info.win = mlx_new_window(all->info.mlx, all->game.r.width, all->game.r.height, "mlx");
	all->img.img = mlx_new_image(all->info.mlx, all->game.r.width, all->game.r.height);
	all->img.data = (int *)mlx_get_data_addr(all->img.img, &all->img.bpp, &all->img.size_l, &all->img.endian);

	mlx_loop_hook(all->info.mlx, &ft_main_loop, all);
	mlx_hook(all->info.win, X_EVENT_KEY_PRESS, 0, &ft_press_key, all);
	mlx_hook(all->info.win, X_EVENT_KEY_EXIT, 17, &ft_close, all);
	ft_bgm_start();
    mlx_loop(all->info.mlx);
	if (!(&ft_main_loop))
		ft_bgm_end();
	return (0);
}
