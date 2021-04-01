/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:53:10 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/01 16:31:08 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_put_step_side_value(t_all *all)
{
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
}

void	ft_dda(t_all *all)
{
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
			all->info.side = 1;
		}
		if (all->map.map[all->info.mapX][all->info.mapY] == '1')
			all->info.hit = 1;
	}
}

void	ft_draw_wall(t_all *all)
{
	if (all->info.side == 0)
		all->info.perpWallDist = (all->info.mapX - all->info.posX + 
				(1 - all->info.stepX) / 2) / all->info.rayDirX;
	else
		all->info.perpWallDist = (all->info.mapY - all->info.posY +
				(1 - all->info.stepY) / 2) / all->info.rayDirY;
	all->info.lineHeight = (int)(all->game.r.height / all->info.perpWallDist);
	all->info.drawStart = (-all->info.lineHeight / 2) + (all->game.r.height / 2);
	if (all->info.drawStart < 0)
		all->info.drawStart = 0;
	all->info.drawEnd = (all->info.lineHeight / 2) + (all->game.r.height / 2);
	if (all->info.drawEnd >= all->game.r.height)
		all->info.drawEnd = all->game.r.height - 1;
	all->info.texNum = ft_set_texnum(all);
	
	if (all->info.side == 0)
		all->info.wallX = all->info.posY + all->info.perpWallDist * all->info.rayDirY;
	else
        all->info.wallX = all->info.posX + all->info.perpWallDist * all->info.rayDirX;
	all->info.wallX -= floor(all->info.wallX);
}

void	ft_paint_texture(t_all *all, int x)
{
	all->info.texX = (int)(all->info.wallX * (double)all->info.texWidth);
	if (all->info.side == 0 && all->info.rayDirX > 0)
		all->info.texX = all->info.texWidth - all->info.texX - 1;
	if (all->info.side == 1 && all->info.rayDirY < 0)
		all->info.texX = all->info.texWidth - all->info.texX - 1;

	all->info.step = 1.0 * all->info.texHeight / all->info.lineHeight;
	all->info.texPos = (all->info.drawStart - all->game.r.height / 2 + all->info.lineHeight / 2) * all->info.step;
	
	int y;
	y = all->info.drawStart; 
	while (y < all->info.drawEnd)
	{
		all->info.texY = (int)all->info.texPos & (all->info.texHeight - 1);
		all->info.texPos += all->info.step;
		all->info.color = all->info.tex[all->info.texNum][all->info.texHeight * all->info.texY + all->info.texX];
		if (all->info.side == 1)
			all->info.color = (all->info.color >> 1) & 8355711;
		all->info.buf[y][x] = all->info.color;
		all->img.data[y * all->img.size_l / all->img.bpp * 8 + x] = all->info.buf[y][x];
		y++;
	}
}
