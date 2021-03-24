/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textured.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:30:19 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/24 23:54:07 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw(t_all *all)
{
	int x;
	int y;

	y = 0;
	while (y < all->game.r.height)
	{
		x = 0;
		while (x < all->game.r.width)
		{
			all->info.img.data[y * all->game.r.width + x] = all->info.buf[y][x];
			x++;
		}
		y++;
	}
}

void	calc(t_all *all)
{
	int	x;

	x = 0;
	while (x < all->game.r.width)
	{
		all->info.cameraX = 2 * x / (double)(all->game.r.width) - 1;
		all->info.rayDirX = all->info.dirX + all->info.planeX * all->info.cameraX;
		all->info.rayDirY = all->info.dirY + all->info.planeY * all->info.cameraX;

		all->info.mapX = (int)all->info.posX;
		all->info.mapY = (int)all->info.posY;

		all->info.deltaDistX = fabs(1 / all->info.rayDirX);
		all->info.deltaDistY = fabs(1 / all->info.rayDirY);

		all->info.hit = 0;

		if (all->info.rayDirX < 0)
		{
			all->info.stepX = -1;
			all->info.sideDistX = (all->info.posX - all->info.mapX) * all->info.deltaDistX;
		}
		else
		{
			all->info.stepX = 1;
			all->info.sideDistX = (all->info.mapX + 1.0 - all->info.posX) * all->info.deltaDistX;
		}
		if (all->info.rayDirY < 0)
		{
			all->info.stepY = -1;
			all->info.sideDistY = (all->info.posY - all->info.mapY) * all->info.deltaDistY;
		}
		else
		{
			all->info.stepY = 1;
			all->info.sideDistY = (all->info.mapY + 1.0 - all->info.posY) * all->info.deltaDistY;
		}
		while (all->info.hit == 0)
		{
			if (all->info.sideDistX < all->info.sideDistY)
			{
				all->info.sideDistX += all->info.deltaDistX;
				all->info.mapX += all->info.stepX;
				all->info.side = 0;
			}
			else
			{
				all->info.sideDistY += all->info.deltaDistY;
				all->info.mapY += all->info.stepY;
				all->info.side = 0;
			}
			if (all->map.map[all->info.mapX][all->info.mapY] > 0)
				all->info.hit = 1;
		}
		if (all->info.side == 0)
			all->info.perpWallDist = (all->info.mapX - all->info.posX + (1 - all->info.stepX) / 2) / all->info.rayDirX;
		else
			all->info.perpWallDist = (all->info.mapY - all->info.posY + (1 - all->info.stepY) / 2) / all->info.rayDirY;

		int lineHeight = (int)(all->game.r.height / all->info.perpWallDist);

		int drawStart = -lineHeight / 2 + all->game.r.height / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + all->game.r.height / 2;
		if (drawEnd >= all->game.r.height)
			drawEnd = all->game.r.height - 1;
		
		int	texNum = all->map.map[all->info.mapX][all->info.mapY];

		double wallX;
		if (all->info.side == 0)
			wallX = all->info.posY + all->info.perpWallDist * all->info.rayDirY;
		else
			wallX = all->info.posX + all->info.perpWallDist * all->info.rayDirX;
		wallX -= floor(wallX);

		int texX = (int)(wallX * (double)texWidth);
		if (all->info.side == 0 && all->info.rayDirX > 0)
			texX = texWidth - texX - 1;
		if (all->info.side == 1 && all->info.rayDirY < 0)
			texX = texWidth - texX - 1;

		double step = 1.0 * texHeight / lineHeight;

		double texPos = (drawStart - all->game.r.height / 2 + lineHeight / 2) * step;
		
		int y = drawStart;
		while (y < drawEnd)
		{
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			int color = all->info.texture[texNum][texHeight * texY + texX];
			if (all->info.side == 1)
				color = (color >> 1) & 8355711;
			all->info.buf[y][x] = color;
			y++;
		}

		x++;
	}
}

int	main_loop(t_all *all)
{
	calc(all);
	draw(all);
	return (0);
}

int	key_press(int key, t_all *all)
{
	if (key == KEY_W)
	{
		if (!(all->map.map[(int)(all->info.posX - all->info.dirX * all->info.moveSpeed)][(int)(all->info.posY)]))
			all->info.posX += all->info.dirX * all->info.moveSpeed;
		if (!(all->map.map[(int)(all->info.posY)][(int)(all->info.posY + all->info.dirY * all->info.moveSpeed)]))
			all->info.posY += all->info.dirY * all->info.moveSpeed;
	}
	if (key == KEY_S)
	{
		if (!(all->map.map[(int)(all->info.posX - all->info.dirX * all->info.moveSpeed)][(int)(all->info.moveSpeed)]))
			all->info.posX -= all->info.dirX * all->info.moveSpeed;
		if (!(all->map.map[(int)(all->info.posX)][(int)(all->info.posY - all->info.dirY * all->info.moveSpeed)]))
			all->info.posY -= all->info.dirY * all->info.moveSpeed;
	}
	if (key == KEY_D)
	{
		all->info.oldDirX = all->info.dirX;
		all->info.dirX = all->info.dirX * cos(-all->info.rotSpeed) - all->info.dirY * sin(-all->info.rotSpeed);
		all->info.dirY = all->info.oldDirX * sin(-all->info.rotSpeed) + all->info.dirY * cos(-all->info.rotSpeed);
		all->info.oldPlaneX = all->info.planeX;
		all->info.planeX = all->info.planeX * cos(-all->info.rotSpeed) - all->info.planeY * sin(-all->info.rotSpeed);
		all->info.planeY = all->info.oldPlaneX * sin(-all->info.rotSpeed) + all->info.planeY * cos(-all->info.rotSpeed);
	}
	if (key == KEY_A)
	{
		all->info.oldDirX = all->info.dirX;
		all->info.dirX = all->info.dirX * cos(all->info.rotSpeed) - all->info.dirY * sin(all->info.rotSpeed);
		all->info.dirY = all->info.oldDirX * sin(all->info.rotSpeed) + all->info.dirY * cos(all->info.rotSpeed);
		all->info.oldPlaneX = all->info.planeX;
		all->info.planeX = all->info.planeX * cos(all->info.rotSpeed) - all->info.planeY * sin(all->info.rotSpeed);
		all->info.planeY = all->info.oldPlaneX * sin(all->info.rotSpeed) + all->info.planeY * cos(all->info.rotSpeed);
		
	}
	if (key == KEY_ESC)
		exit(0);
	return (0);
}

void	ft_load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int x;
	int y;

	img->img = mlx_xpm_file_to_image(info->mlx, path, &(img->img_width), &(img->img_height));
	img->data = (int *)mlx_get_data_addr(img->img, &(img->bpp), &(img->size_l), &(img->endian));
	y = 0;
	while (x < img->img_height)
	{
		x = 0;
		while (y < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	ft_load_texture(t_info *info)
{
	t_img	img;

	ft_load_image(info, info->texture[0], "pics/wall_e.xpm", &img);
	ft_load_image(info, info->texture[1], "pics/wall_n.xpm", &img);
	ft_load_image(info, info->texture[2], "pics/wall_s.xpm", &img);
	ft_load_image(info, info->texture[3], "pics/wall_w.xpm", &img);
	ft_load_image(info, info->texture[4], "pics/sprite.xpm", &img);
}
