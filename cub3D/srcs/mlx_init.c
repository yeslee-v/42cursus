/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeslee <yeslee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:40:53 by yeslee            #+#    #+#             */
/*   Updated: 2021/04/09 11:48:28 by yeslee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_t_info_init(t_all *all)
{
	all->info.pos_x = all->map.player_row;
	all->info.pos_y = all->map.player_col;
	all->info.move_s = 0.49;
	all->info.rot_s = 0.49;
	all->info.tex_w = 64;
	all->info.tex_h = 64;
}

void	ft_nesw_intro(t_all *all, int i, int j)
{
	if ((all->map.map[i][j] == 'N') || (all->map.map[i][j] == 'E')
			|| (all->map.map[i][j] == 'S') || (all->map.map[i][j] == 'W'))
	{
		all->map.player_row = i + 0.5;
		all->map.player_col = j + 0.5;
		ft_nesw_init(all, i, j);
	}
}

void	ft_nesw_init(t_all *all, int i, int j)
{
	if (all->map.map[i][j] == 'N')
	{
		all->info.dir_x = -1.0;
		all->info.dir_y = 0.0;
		all->info.plane_x = 0.0;
		all->info.plane_y = 0.66;
	}
	if (all->map.map[i][j] == 'E')
	{
		all->info.dir_x = 0.0;
		all->info.dir_y = 1.0;
		all->info.plane_x = 0.66;
		all->info.plane_y = 0.0;
	}
	if (all->map.map[i][j] == 'S')
	{
		all->info.dir_x = 1.0;
		all->info.dir_y = 0.0;
		all->info.plane_x = 0.0;
		all->info.plane_y = -0.66;
	}
	if (all->map.map[i][j] == 'W')
	{
		all->info.dir_x = 0.0;
		all->info.dir_y = -1.0;
		all->info.plane_x = -0.66;
		all->info.plane_y = 0.0;
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
	
	all->info.camera_x = (2.0 * x / (double)(all->game.r.width)) - 1.0;
    all->info.ray_x = all->info.dir_x + all->info.plane_x * all->info.camera_x;
    all->info.ray_y = all->info.dir_y + all->info.plane_y * all->info.camera_x;

    all->info.map_x = (int)(all->info.pos_x);
    all->info.map_y = (int)(all->info.pos_y);

    all->info.delta_x = fabs(1.0 / all->info.ray_x);
    all->info.delta_y = fabs(1.0 / all->info.ray_y);
}
