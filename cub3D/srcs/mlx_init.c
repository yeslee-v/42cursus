/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:40:53 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/04 16:14:57 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_t_info_init(t_all *all)
{
	all->info.posX = all->map.player_row;
	all->info.posY = all->map.player_col;
	all->info.moveSpeed = 0.5;
	all->info.rotSpeed = 0.5;
	all->info.texWidth = 64;
	all->info.texHeight = 64;
}

void	ft_nesw_intro(t_all *all, int i, int j)
{
	if ((all->map.map[i][j] == 'N') || (all->map.map[i][j] == 'E')
			|| (all->map.map[i][j] == 'S') || (all->map.map[i][j] == 'W'))
	{
		all->map.player_row = i;
		all->map.player_col = j;
		ft_nesw_init(all, i, j);
	}
}

void	ft_nesw_init(t_all *all, int i, int j)
{
	if (all->map.map[i][j] == 'N')
	{
		all->info.dirX = -1.0;
		all->info.dirY = 0.0;
		all->info.planeX = 0.0;
		all->info.planeY = 0.66;
	}
	if (all->map.map[i][j] == 'E')
	{
		all->info.dirX = 0.0;
		all->info.dirY = 1.0;
		all->info.planeX = 0.66;
		all->info.planeY = 0.0;
	}
	if (all->map.map[i][j] == 'S')
	{
		all->info.dirX = 1.0;
		all->info.dirY = 0.0;
		all->info.planeX = 0.0;
		all->info.planeY = -0.66;
	}
	if (all->map.map[i][j] == 'W')
	{
		all->info.dirX = 0.0;
		all->info.dirY = -1.0;
		all->info.planeX = -0.66;
		all->info.planeY = 0.0;
	}
}

void	ft_set_screen_size(t_all *all)
{
	mlx_get_screen_size(all->info.mlx, &all->scr.c_sizeX, &all->scr.c_sizeY);
	if (all->scr.c_sizeX < all->game.r.width)
		all->game.r.width = all->scr.c_sizeX;
	if (all->scr.c_sizeY < all->game.r.height)
		all->game.r.height = all->scr.c_sizeY;
}

void	ft_calc_save_init(t_all *all, int x)
{
    all->info.hit = 0;
	
	all->info.cameraX = (2 * x / (double)(all->game.r.width)) - 1;
    all->info.rayDirX = all->info.dirX + all->info.planeX * all->info.cameraX;
    all->info.rayDirY = all->info.dirY + all->info.planeY * all->info.cameraX;

    all->info.mapX = (int)(all->info.posX);
    all->info.mapY = (int)(all->info.posY);

    all->info.deltaDistX = fabs(1 / all->info.rayDirX);
    all->info.deltaDistY = fabs(1 / all->info.rayDirY);
}
