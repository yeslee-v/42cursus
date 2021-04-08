/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:45:15 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/08 21:41:16 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	return (num);
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
            all->img.data[y * all->img.size_l / all->img.bpp * 8 + x] =
				all->info.buf[y][x];
			x++;
		}
		y++;
	}
    mlx_put_image_to_window(all->info.mlx, all->info.win, all->img.img, 0, 0);
}

void    ft_load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int x;
	int y;

    img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width,
			&img->img_height);
    img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l,
			&img->endian);
    y = 0;
	while (y < img->img_height)
    {
		x = 0;
        while (x < img->img_width)
        {
            texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
        }
		y++;
    }
    mlx_destroy_image(info->mlx, img->img);
}

void    load_texture(t_all *all)
{
	t_img	img;

	printf("n: %s\n", all->game.n);
    ft_load_image(&all->info, all->info.tex[0], all->game.n, &img);
    ft_load_image(&all->info, all->info.tex[1], all->game.s, &img);
    ft_load_image(&all->info, all->info.tex[2], all->game.w, &img);
    ft_load_image(&all->info, all->info.tex[3], all->game.e, &img);
    ft_load_image(&all->info, all->info.tex[4], all->game.sp, &img);
}
