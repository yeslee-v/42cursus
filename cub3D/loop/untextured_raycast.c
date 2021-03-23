/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untextured_raycast.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:05:26 by yeslee            #+#    #+#             */
/*   Updated: 2021/03/23 12:45:52 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	verLine(t_all *all, int x, int y1, int y2, int color)
{
	int y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(all->info.mlx, all->info.win, x, y, color);
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

		int color;
		if (all->map.map[all->info.mapY][all->info.mapX] == 1)
			color = 0xFF0000;
		if (all->map.map[all->info.mapY][all->info.mapX] == 2)
			color = 0x00FF00;
		if (all->map.map[all->info.mapY][all->info.mapX] == 3)
			color = 0x0000FF;
		if (all->map.map[all->info.mapY][all->info.mapX] == 4)
			color = 0xFFFFFF;
		else
			color = 0xFFFF00;
		if (all->info.side == 1)
			color /= 2;
		verLine(all, x, drawStart, drawEnd, color);
		x++;
	}
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

int	main_loop(t_all *all)
{
	calc(all);
	return (0);
}
